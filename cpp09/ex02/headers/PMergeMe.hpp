#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <ctime>
#include <algorithm>

class PMergeMe {
    public:
        PMergeMe();
        PMergeMe(const PMergeMe &other);
        PMergeMe &operator=(const PMergeMe &other);
        ~PMergeMe();
        template <typename Container>
        static std::vector<Container> createPairs(const Container &array);
        template <typename Container>
        static void sortEachPair(std::vector<Container> &splitArray);
        template <typename Container>
        static void insertionSortPairs(std::vector<Container> &splitArray);
        template <typename Container>
        static Container buildJacobInsertionSequence(size_t arrayLen);
        template <typename Container>
        static void sortByLargerValue(std::vector<Container> &sortedSplitArray);
        template <typename Container>
        static Container createS(const std::vector<Container> &sortedSplitArray, typename Container::value_type straggler);
        template <typename Container>
        static Container mergeInsertionSort(Container &array, int flag);
        template <typename Container>
        static double measureSortingTime(Container &array, int flag);
};

#include "../srcs/PMergeMe.tpp"
#endif
