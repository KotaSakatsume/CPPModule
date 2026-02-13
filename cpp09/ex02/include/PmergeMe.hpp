#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime> 
#include <sstream>
#include <climits>
#include <cstdlib>

// 色つけ用
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &src);
    ~PmergeMe();

    void run(int argc, char **argv);

private:
    std::vector<int> _vec;
    std::deque<int>  _deq;


    void parseInput(int argc, char **argv);
    template <typename T>
    void printContainer(const T &container, const std::string &name);
    
    void sortVector(std::vector<int> &arr);
    std::vector<int> mergeInsertionSortVector(std::vector<int> &arr);
    
    void sortDeque(std::deque<int> &arr);
    std::deque<int> mergeInsertionSortDeque(std::deque<int> &arr);

    size_t getJacobsthal(size_t n);
};

#endif
