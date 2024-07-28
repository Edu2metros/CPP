#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <iterator>
#include <stdexcept>
#include <string>
#include <cstring>

class PmergeMe {

    private:
        std::vector<int> _v1;
        std::vector<int> _v2;
        std::vector<int> _v3;

        std::deque<int> _d1;
        std::deque<int> _d2;
        std::deque<int> _d3;
    
    public:
        //Ortdohox Canonical Form
        PmergeMe(int argc, char **argv);
        PmergeMe(const PmergeMe &p);
        PmergeMe &operator=(const PmergeMe &p);
        ~PmergeMe();
        
        // Methods
        void printMsg(std::string msg);
        void run2(void);
};