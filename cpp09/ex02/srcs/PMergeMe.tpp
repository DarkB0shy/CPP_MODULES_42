#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "../headers/PMergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe &other) {*this = other;}

PMergeMe &PMergeMe::operator=(const PMergeMe &other) {
    if (this != &other) {}
    return *this;
}

PMergeMe::~PMergeMe() {}

template <typename Container, typename Iterator>
Iterator advanceIterator(Iterator it, size_t n) {
    while (n--) ++it;
    return it;
}

template <typename Container>
std::vector<Container> PMergeMe::createPairs(const Container &array) {
    std::vector<Container> splitArray;
    typename Container::const_iterator it = array.begin();
    while (it != array.end()) {
        Container pair;
        pair.push_back(*it);
        ++it;
        if (it != array.end()) {
            pair.push_back(*it);
            ++it;
        }
        splitArray.push_back(pair);
    }
    return splitArray;
}

template <typename Container>
void PMergeMe::sortEachPair(std::vector<Container> &splitArray) {
    for (typename std::vector<Container>::iterator it = splitArray.begin(); it != splitArray.end(); ++it) {
        if (it->size() == 2 && (*it).front() > (*it).back())
            std::swap((*it).front(), (*it).back());
    }
}

template <typename Container>
void PMergeMe::insertionSortPairs(std::vector<Container> &splitArray) {
    for (size_t i = 1; i < splitArray.size(); ++i) {
        Container element = splitArray[i];
        size_t j = i;
        while (j > 0 && element.back() < splitArray[j - 1].back()) {
            splitArray[j] = splitArray[j - 1];
            --j;
        }
        splitArray[j] = element;
    }
}

template <typename Container>
Container PMergeMe::buildJacobInsertionSequence(size_t arrayLen) {
    Container sequence;
    int a = 0, b = 1;
    size_t index = 3;
    while (true) {
        int jacobNum = a + 2 * b;
        if (jacobNum >= static_cast<int>(arrayLen) - 1)
            break;
        sequence.push_back(jacobNum);
        a = b;
        b = jacobNum;
        ++index;
    }
    return sequence;
}

template <typename Container>
void PMergeMe::sortByLargerValue(std::vector<Container> &sortedSplitArray) {
    insertionSortPairs<Container>(sortedSplitArray);
}

template <typename Container>
Container PMergeMe::createS(const std::vector<Container> &sortedSplitArray, typename Container::value_type straggler) {
    Container S;
    Container pend;
    for (typename std::vector<Container>::const_iterator it = sortedSplitArray.begin(); it != sortedSplitArray.end(); ++it) {
        S.push_back(it->back());
        pend.push_back(it->front());
    }
    S.insert(S.begin(), pend.front());
    Container jacobSequence = buildJacobInsertionSequence<Container>(pend.size());
    for (typename Container::const_iterator it = jacobSequence.begin(); it != jacobSequence.end(); ++it) {
        typename Container::value_type item = *advanceIterator<Container>(pend.begin(), *it - 1);
        typename Container::iterator insertionPoint = std::upper_bound(S.begin(), S.end(), item);
        S.insert(insertionPoint, item);
    }
    for (size_t i = 1; i < pend.size(); ++i) {
        if (std::find(jacobSequence.begin(), jacobSequence.end(), i) == jacobSequence.end()) {
            typename Container::value_type item = *advanceIterator<Container>(pend.begin(), i - 1);
            typename Container::iterator insertionPoint = std::upper_bound(S.begin(), S.end(), item);
            S.insert(insertionPoint, item);
        }
    }
    if (straggler != -1) {
        typename Container::iterator insertionPoint = std::upper_bound(S.begin(), S.end(), straggler);
        S.insert(insertionPoint, straggler);
    }
    return S;
}

template <typename Container>
Container PMergeMe::mergeInsertionSort(Container &array, int flag) {
    bool hasStraggler = (array.size() % 2 != 0);
    typename Container::value_type straggler = hasStraggler ? array.back() : -1;
    if (hasStraggler) array.pop_back();
    std::vector<Container> splitArray = createPairs<Container>(array);
    sortEachPair<Container>(splitArray);
    sortByLargerValue<Container>(splitArray);
    Container sortedArray = createS<Container>(splitArray, straggler);
    if (flag) {
        std::cout << "Sorted Array: ";
        for (typename Container::const_iterator it = sortedArray.begin(); it != sortedArray.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    return sortedArray;
}

template <typename Container>
double PMergeMe::measureSortingTime(Container &array, int flag) {
    std::clock_t start = std::clock();
    mergeInsertionSort<Container>(array, flag);
    std::clock_t end = std::clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

#endif
