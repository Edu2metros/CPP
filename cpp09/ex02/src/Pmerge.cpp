#include "PmergeMe.hpp"

void PmergeMe::printMsg(std::string msg) {
    #ifdef DEBUG
        std::cout << msg << std::endl;
    #endif
}

PmergeMe::PmergeMe(int argc, char **argv) {
    printMsg("Constructor PmergeMe called");
    for(int i = 1; i < argc; i++)
	{
        _v1.push_back(atoi(argv[i]));
		_d1.push_back(atoi(argv[i]));
	}
    _odd = -1;
}

PmergeMe::PmergeMe(const PmergeMe &p) {
	printMsg("Copy Constructor PmergeMe called");
	_v1 = p._v1;
	_pairs = p._pairs;
	_first = p._first;
	_second = p._second;
	_odd = p._odd;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &p) {
	printMsg("Assignment Operator PmergeMe called");
	if(this != &p)
	{
		_v1 = p._v1;
		_pairs = p._pairs;
		_first = p._first;
		_second = p._second;
		_odd = p._odd;
	}
	return *this;
}

PmergeMe::~PmergeMe() {
    printMsg("Destructor PmergeMe called");
}

void PmergeMe::_makePairVector(void)
{
    if(_v1.size() % 2 == 1)
    {
        _odd = _v1.back();
        _v1.pop_back();
    }
    for(std::vector<int>::size_type i = 0; i < _v1.size(); i += 2)
        _pairs.push_back(std::make_pair(_v1[i], _v1[i + 1]));
    
    for(std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); ++it)
    {
        if(it->first < it->second)
            std::swap(it->first, it->second);
    }
    std::sort(_pairs.begin(), _pairs.end());
}

void PmergeMe::_separateVector(void)
{
    for(std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); ++it)
    {
        _first.push_back(it->first);
        _second.push_back(it->second);
    }
    if(_odd != -1)
        _second.push_back(_odd);
}

void PmergeMe::_jacobsthalVector(void)
{
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    if (_second.size() > 0)
        jacobsthal.push_back(1);
    while (true)
    {
        int nextNumber = jacobsthal[jacobsthal.size() - 1] * 2 + jacobsthal[jacobsthal.size() - 2];
        if (nextNumber >= _second.size())
            break;
        jacobsthal.push_back(nextNumber);
    }
    if (jacobsthal.size() > 1)
        jacobsthal.erase(jacobsthal.begin() + 1);

    std::vector<int> insertion;
    while (insertion.size() < _second.size())
    {
        if (!jacobsthal.empty())
        {
            int last = insertion.empty() ? -1 : insertion.back();
            int jacob = jacobsthal.front();
            jacobsthal.erase(jacobsthal.begin());

            while (jacob > last && insertion.size() < _second.size())
            {
                if (std::find(insertion.begin(), insertion.end(), jacob) == insertion.end())
                    insertion.push_back(jacob);
                --jacob;
            }
        }
        else
        {
            int missing = _second.size() - 1;
            while (insertion.size() < _second.size())
                insertion.push_back(missing--);
        }
    }
}

void PmergeMe::_sortVector(void)
{
    for(std::vector<int>::iterator iterator = _second.begin(); iterator != _second.end(); ++iterator)
    {
        int value = *iterator;
        std::vector<int>::iterator position = std::upper_bound(_first.begin(), _first.end(), value);
        _first.insert(position, value);
    }
}

double PmergeMe::_runVector(void)
{
	clock_t start, end;
	double timeVector;
	start = clock();

	_makePairVector();
    _separateVector();
    _jacobsthalVector();
    _sortVector();

	end = clock();
	timeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	return timeVector;
}

void PmergeMe::_makePairDeque(void)
{
    if(_d1.size() % 2 == 1)
    {
        _odd = _d1.back();
        _d1.pop_back();
    }
    for(std::deque<int>::size_type i = 0; i < _d1.size(); i += 2)
        _dpairs.push_back(std::make_pair(_d1[i], _d1[i + 1]));
    
    for(std::deque<std::pair<int, int> >::iterator it = _dpairs.begin(); it != _dpairs.end(); ++it)
    {
        if(it->first < it->second)
            std::swap(it->first, it->second);
    }
    std::sort(_dpairs.begin(), _dpairs.end());
}

void PmergeMe::_separateDeque(void)
{
    for(std::deque<std::pair<int, int> >::iterator it = _dpairs.begin(); it != _dpairs.end(); ++it)
    {
        _dfirst.push_back(it->first);
        _dsecond.push_back(it->second);
    }
    if(_odd != -1)
        _dsecond.push_back(_odd);
}

void PmergeMe::_jacobsthalDeque(void)
{
    std::deque<int> jacobsthal;
    jacobsthal.push_back(0);
    if (_dsecond.size() > 0)
        jacobsthal.push_back(1);
    while (true)
    {
        int nextNumber = jacobsthal[jacobsthal.size() - 1] * 2 + jacobsthal[jacobsthal.size() - 2];
        if (nextNumber >= _dsecond.size())
            break;
        jacobsthal.push_back(nextNumber);
    }
    if (jacobsthal.size() > 1)
        jacobsthal.erase(jacobsthal.begin() + 1);

    std::deque<int> insertion;
    while (insertion.size() < _dsecond.size())
    {
        if (!jacobsthal.empty())
        {
            int last = insertion.empty() ? -1 : insertion.back();
            int jacob = jacobsthal.front();
            jacobsthal.pop_front();

            while (jacob > last && insertion.size() < _dsecond.size())
            {
                if (std::find(insertion.begin(), insertion.end(), jacob) == insertion.end())
                    insertion.push_back(jacob);
                --jacob;
            }
        }
        else
        {
            int missing = _dsecond.size() - 1;
            while (insertion.size() < _dsecond.size())
                insertion.push_back(missing--);
        }
    }
}

void PmergeMe::_sortDeque(void)
{
    for(std::deque<int>::iterator iterator = _dsecond.begin(); iterator != _dsecond.end(); ++iterator)
    {
        int value = *iterator;
        std::deque<int>::iterator position = std::upper_bound(_dfirst.begin(), _dfirst.end(), value);
        _dfirst.insert(position, value);
    }
}

double PmergeMe::_runDeque(void)
{
	_odd = -1;
    clock_t start, end;
    double timeDeque;
    start = clock();

    _makePairDeque();
    _separateDeque();
    _jacobsthalDeque();
    _sortDeque();

    end = clock();
    timeDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    return timeDeque;
}

void PmergeMe::run(void)
{
	std::cout << "Before: ";
	std::copy(_v1.begin(), _v1.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	//Run the vector container
	double timeVector = _runVector();
	//Run the deque container
	double timeDeque = _runDeque();

	std::cout << "After: ";
	std::copy(_first.begin(), _first.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::cout << "Time Vector: " << timeVector << " ms" << std::endl;
	std::cout << "Time Deque: " << timeDeque << " ms" << std::endl;
}
