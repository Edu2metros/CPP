#include "PmergeMe.hpp"

void PmergeMe::printMsg(std::string msg) {
    #ifdef DEBUG
        std::cout << msg << std::endl;
    #endif
}

PmergeMe::PmergeMe(int argc, char **argv) {
    printMsg("Constructor PmergeMe called");
    for(int i = 1; i < argc; i++)
        _v1.push_back(atoi(argv[i]));
    _odd = -1;
}

/* PmergeMe::PmergeMe(const PmergeMe &p) {
    printMsg("Copy Constructor PmergeMe called");

    if(this != &p) {
        _v1 = p._v1;
        _v2 = p._v2;
        _v3 = p._v3;

        _d1 = p._d1;
        _d2 = p._d2;
        _d3 = p._d3;
    }
}

PmergeMe &PmergeMe::operator=(const PmergeMe &p) {
    printMsg("Operator = PmergeMe called");

    if(this != &p) {
        _v1 = p._v1;
        _v2 = p._v2;
        _v3 = p._v3;

        _d1 = p._d1;
        _d2 = p._d2;
        _d3 = p._d3;
    }

    re *turn *this;
*/

PmergeMe::~PmergeMe() {
    printMsg("Destructor PmergeMe called");
}

void PmergeMe::_makePair(void)
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

void PmergeMe::_separate(void)
{
    for(std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); ++it)
    {
        _first.push_back(it->first);
        _second.push_back(it->second);
    }
    if(_odd != -1)
        _second.push_back(_odd);
}

void PmergeMe::_jacobsthal(void)
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

void PmergeMe::_sort(void)
{
    for(std::vector<int>::iterator iterator = _second.begin(); iterator != _second.end(); ++iterator)
    {
        int value = *iterator;
        std::vector<int>::iterator position = std::upper_bound(_first.begin(), _first.end(), value);
        _first.insert(position, value);
    }
}

void PmergeMe::run(void)
{
    clock_t start, end;
    double timeVector;
    std::cout << "Before: ";
    std::copy(_v1.begin(), _v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    start = clock();
    _makePair();
    _separate();
    _jacobsthal();
    _sort();
    end = clock();
    std::cout << "After: ";
    timeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    std::copy(_first.begin(), _first.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "Time Vector: " << timeVector << " ms" << std::endl;
}








/* void PmergeMe::run2(void)
{
    clock_t start, end;
    double timeVector, timeDeque;
    std::cout << "Before: ";
    std::copy(_v1.begin(), _v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    size_t mid = _v1.size() / 2;
    for (size_t i = 0; i < mid; i++)
    {
        _v2.push_back(_v1.back());
        _d2.push_back(_d1.back());
        _v1.pop_back();
        _d1.pop_back();
    }

    std::cout << "After: \n";

    start = clock();
    std::sort(_v1.begin(), _v1.end());
    std::sort(_v2.begin(), _v2.end());
    std::merge(_v1.begin(), _v1.end(), _v2.begin(), _v2.end(), std::back_inserter(_v3));
    end = clock();
    timeVector = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    start = clock();
    std::sort(_d1.begin(), _d1.end());
    std::sort(_d2.begin(), _d2.end());
    std::merge(_d1.begin(), _d1.end(), _d2.begin(), _d2.end(), std::back_inserter(_d3));
    end = clock();
    timeDeque = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    std::cout << "Vector: ";
    std::copy(_v3.begin(), _v3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl << "Deque: ";
    std::copy(_d3.begin(), _d3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "Time Vector: " << timeVector << " ms" << std::endl;
    std::cout << "Time Deque: " << timeDeque << " ms" << std::endl;
    std::cout << std::endl;
}
 */