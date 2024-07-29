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
		//Vector Methods
        std::vector<int> _v1;
        std::vector<std::pair<int, int> > _pairs;
        std::vector<int> _first, _second;

        void _makePairVector(void);
        void _separateVector(void);
        void _jacobsthalVector(void);
        void _sortVector(void);
		double _runVector(void);

		//Deque Methods
		std::deque<int> _d1;
		std::deque<std::pair<int, int> > _dpairs;
		std::deque<int> _dfirst, _dsecond;

		void _makePairDeque(void);
		void _separateDeque(void);
		void _jacobsthalDeque(void);
		void _sortDeque(void);
		double _runDeque(void);
	
    public:
        //Ortdohox Canonical Form
        PmergeMe(int argc, char **argv);
        PmergeMe(const PmergeMe &p);
        PmergeMe &operator=(const PmergeMe &p);
        ~PmergeMe();
        
        // Methods
        void printMsg(std::string msg);
        void run(void);
};