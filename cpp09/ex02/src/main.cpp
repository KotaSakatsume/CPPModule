#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << RED << "Error: Invalid number of arguments." << RESET << std::endl;
        std::cerr << "Usage: ./PmergeMe [positive integer sequence]" << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter;
        sorter.run(argc, argv);
    } catch (const std::exception &e) {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        return 1;
    }

    return 0;
}
