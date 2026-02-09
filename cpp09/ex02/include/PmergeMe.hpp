#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm> // for std::lower_bound
#include <ctime>     // for clock()
#include <sstream>
#include <climits>
#include <cstdlib>

// 色つけ用
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

class PmergeMe {
public:
    // Orthodox Canonical Form
    PmergeMe();
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &src);
    ~PmergeMe();

    // メイン実行関数
    void run(int argc, char **argv);

private:
    // データコンテナ
    std::vector<int> _vec;
    std::deque<int>  _deq;

    // --- Helper Functions ---
    // 入力解析
    void parseInput(int argc, char **argv);
    // 出力
    template <typename T>
    void printContainer(const T &container, const std::string &name);
    
    // --- Algorithm Logic (Vector) ---
    void sortVector(std::vector<int> &arr);
    std::vector<int> mergeInsertionSortVector(std::vector<int> &arr);
    
    // --- Algorithm Logic (Deque) ---
    void sortDeque(std::deque<int> &arr);
    std::deque<int> mergeInsertionSortDeque(std::deque<int> &arr);

    // --- Shared Logic ---
    size_t getJacobsthal(size_t n);
};

#endif
