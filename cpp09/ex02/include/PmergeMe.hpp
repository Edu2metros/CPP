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
        int _odd;
        std::vector<int> _v1;
        std::vector<std::pair<int, int> > _pairs;
        std::vector<int> _first, _second;

        void _makePair(void);
        void _separate(void);
        void _jacobsthal(void);
        void _sort(void);

    public:
        //Ortdohox Canonical Form
        PmergeMe(int argc, char **argv);
        PmergeMe(const PmergeMe &p);
        PmergeMe &operator=(const PmergeMe &p);
        ~PmergeMe();
        
        // Methods
        void printMsg(std::string msg);
        void run(void);


        void run2(void);
};