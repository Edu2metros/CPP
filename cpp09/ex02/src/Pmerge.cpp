#include "PmergeMe.hpp"

void PmergeMe::printMsg(std::string msg) {
    #ifdef DEBUG
        std::cout << msg << std::endl;
    #endif
}

PmergeMe::PmergeMe(int argc, char **argv) {
    printMsg("Constructor PmergeMe called");

    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        _v1.push_back(number);
        _d1.push_back(number);
    }
}

PmergeMe::PmergeMe(const PmergeMe &p) {
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

    return *this;
}

PmergeMe::~PmergeMe() {
    printMsg("Destructor PmergeMe called");
}

void PmergeMe::run2(void)
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
