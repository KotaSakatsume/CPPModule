#include "PmergeMe.hpp"

// ==========================================
// Global Counter & Helper Struct
// ==========================================
// C++98対応: long long ではなく long を使用
long g_compCount = 0; 

// std::lower_bound で比較回数をカウントするための構造体
struct CompCounter {
    bool operator()(int a, int b) const {
        g_compCount++; // 比較するたびにカウントアップ
        return a < b;
    }
};

// ==========================================
// Orthodox Canonical Form
// ==========================================
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }
PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
    if (this != &src) {
        this->_vec = src._vec;
        this->_deq = src._deq;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

// ==========================================
// Utilities
// ==========================================

size_t PmergeMe::getJacobsthal(size_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2);
}

void PmergeMe::parseInput(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        std::stringstream ss(arg);
        std::string segment;
        
        while (std::getline(ss, segment, ' ')) {
            if (segment.empty()) continue; 
            for (size_t j = 0; j < segment.length(); ++j) {
                if (!isdigit(segment[j])) {
                    throw std::invalid_argument("Non-numeric character detected: " + segment);
                }
            }
            long val = std::atol(segment.c_str());
            if (val < 0 || val > INT_MAX) {
                throw std::invalid_argument("Number out of range: " + segment);
            }
            _vec.push_back(static_cast<int>(val));
            _deq.push_back(static_cast<int>(val));
        }
    }
    if (_vec.empty()) throw std::invalid_argument("No numbers provided.");
}

template <typename T>
void PmergeMe::printContainer(const T &container, const std::string &prefix) {
    std::cout << prefix;
    size_t limit = container.size();
    if (limit > 5) limit = 5; 

    for (size_t i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
        if (i > 20) { 
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;
}

// ==========================================
// Vector Implementation (Merge-Insertion Sort)
// ==========================================

std::vector<int> PmergeMe::mergeInsertionSortVector(std::vector<int> &arr) {
    if (arr.size() <= 1) return arr;

    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;

    if (arr.size() % 2 != 0) {
        straggler = arr.back();
        hasStraggler = true;
        arr.pop_back();
    }

    // ★カウント追加: ペア作成時の比較
    for (size_t i = 0; i < arr.size(); i += 2) {
        g_compCount++; 
        if (arr[i] > arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        } else {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
    }

    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i) {
        winners.push_back(pairs[i].first);
    }

    std::vector<int> sortedWinners = mergeInsertionSortVector(winners);

    std::vector<int> mainChain = sortedWinners;
    std::vector<int> pending;

    for (size_t i = 0; i < mainChain.size(); ++i) {
        int winner = mainChain[i];
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == winner) {
                pending.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    // 最初の敗者を挿入
    mainChain.insert(mainChain.begin(), pending[0]);

    // ★修正: Stragglerをpendingに追加して、Jacobson順序に組み込む
    if (hasStraggler) {
        pending.push_back(straggler);
    }

    size_t jacobsthalIndex = 3; 
    size_t insertedCount = 1;

    while (insertedCount < pending.size()) {
        size_t nextIndex = getJacobsthal(jacobsthalIndex);
        if (nextIndex > pending.size()) nextIndex = pending.size();

        for (size_t i = nextIndex; i > insertedCount; --i) {
            int valToInsert = pending[i - 1];
            
            // ★修正: ペアが存在する場合はその位置まで、存在しない(Straggler)場合は末尾まで探索
            std::vector<int>::iterator limitIt;
            if (i - 1 < sortedWinners.size()) {
                int pairVal = sortedWinners[i - 1];
                limitIt = std::find(mainChain.begin(), mainChain.end(), pairVal);
            } else {
                limitIt = mainChain.end();
            }
            
            // ★カウント追加: lower_bound に CompCounter を渡す
            std::vector<int>::iterator pos = std::lower_bound(
                mainChain.begin(), 
                limitIt, 
                valToInsert, 
                CompCounter() 
            );
            mainChain.insert(pos, valToInsert);
        }
        
        insertedCount = nextIndex;
        jacobsthalIndex++;
    }

    return mainChain;
}

void PmergeMe::sortVector(std::vector<int> &arr) {
    arr = mergeInsertionSortVector(arr);
}

// ==========================================
// Deque Implementation (Comparison Count omitted logic)
// ==========================================

std::deque<int> PmergeMe::mergeInsertionSortDeque(std::deque<int> &arr) {
    if (arr.size() <= 1) return arr;

    std::deque<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;

    if (arr.size() % 2 != 0) {
        straggler = arr.back();
        hasStraggler = true;
        arr.pop_back();
    }

    for (size_t i = 0; i < arr.size(); i += 2) {
        // Deque側は比較回数カウント必須ではないことが多いが、必要ならここにも追加
        if (arr[i] > arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        } else {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
    }

    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i) {
        winners.push_back(pairs[i].first);
    }

    std::deque<int> sortedWinners = mergeInsertionSortDeque(winners);
    std::deque<int> mainChain = sortedWinners;
    std::deque<int> pending;

    for (size_t i = 0; i < mainChain.size(); ++i) {
        int winner = mainChain[i];
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == winner) {
                pending.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    mainChain.insert(mainChain.begin(), pending[0]);

    if (hasStraggler) {
        pending.push_back(straggler);
    }

    size_t jacobsthalIndex = 3;
    size_t insertedCount = 1;

    while (insertedCount < pending.size()) {
        size_t nextIndex = getJacobsthal(jacobsthalIndex);
        if (nextIndex > pending.size()) nextIndex = pending.size();

        for (size_t i = nextIndex; i > insertedCount; --i) {
            int valToInsert = pending[i - 1];
            
            std::deque<int>::iterator limitIt;
            if (i - 1 < sortedWinners.size()) {
                int pairVal = sortedWinners[i - 1];
                limitIt = std::find(mainChain.begin(), mainChain.end(), pairVal);
            } else {
                limitIt = mainChain.end();
            }

            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), limitIt, valToInsert);
            mainChain.insert(pos, valToInsert);
        }
        insertedCount = nextIndex;
        jacobsthalIndex++;
    }

    return mainChain;
}

void PmergeMe::sortDeque(std::deque<int> &arr) {
    arr = mergeInsertionSortDeque(arr);
}

// ==========================================
// Main Execution
// ==========================================

void PmergeMe::run(int argc, char **argv) {
    parseInput(argc, argv);

    std::cout << "Before: ";
    printContainer(_vec, "");

    // --- Measure Vector ---
    g_compCount = 0; // リセット
    std::clock_t startVec = std::clock();
    sortVector(_vec);
    std::clock_t endVec = std::clock();
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000; 
    long vecComparisons = g_compCount; // 保存

    // --- Measure Deque ---
    std::clock_t startDeq = std::clock();
    sortDeque(_deq);
    std::clock_t endDeq = std::clock();
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After:  ";
    printContainer(_vec, "");

    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << timeVec << " us" << std::endl;
              
    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
    
    // ★ここで比較回数を表示
    std::cout << "Number of comparisons (Vector) : " << vecComparisons << std::endl;
}
