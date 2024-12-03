#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

#define OUT_OF_RANGE "Adding this range of iterators would exceed Span's max size."
#define SPAN_FULL "Span is already full!"
#define NOT_ENOUGH_NUMBS "Not enough numbers to find a span."

class Span {
    private:
        std::vector<int> _numbers;
        unsigned int _maxSize;
    public:
        Span();
        Span(const Span &spa);
        ~Span();
        Span &operator=(const Span &spa);
        Span(unsigned int N);
        void addNumber(int num);
        void addNumbers(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end);
        // template <typename Iterator>
        // void addNumbers(Iterator begin, Iterator end) {
        //     if (std::distance(begin, end) + _numbers.size() > _maxSize) {
        //         throw std::out_of_range(OUT_OF_RANGE);
        //     }
        //     _numbers.insert(_numbers.end(), begin, end);                        // The insert method works differently depending on the type of parameters passed
        // }
        void    printElements() const;
        int shortestSpan() const;
        int longestSpan() const;
};

#endif
