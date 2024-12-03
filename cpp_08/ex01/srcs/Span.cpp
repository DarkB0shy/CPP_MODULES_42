#include "../headers/Span.hpp"

Span::Span() : _numbers(), _maxSize(0) {}

Span::Span(const Span &spa) : _numbers(spa._numbers), _maxSize(spa._maxSize) {}

Span::~Span() {}

Span &Span::operator=(const Span &spa) {
    if (this != &spa) {
        _numbers = spa._numbers;
        _maxSize = spa._maxSize;
    }
    return (*this);
}

Span::Span(unsigned int N) : _maxSize(N) {}

void Span::addNumber(int num) {
    if (_numbers.size() >= _maxSize) {throw std::out_of_range(SPAN_FULL);}
    _numbers.push_back(num);
}

void Span::addNumbers(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end) {
    if (std::distance(begin, end) + _numbers.size() > _maxSize) {
        throw std::out_of_range(OUT_OF_RANGE);
    }
    _numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {throw std::logic_error(NOT_ENOUGH_NUMBS);}
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int shortest = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i) {
        int span = sorted[i + 1] - sorted[i];
        if (span < shortest) {shortest = span;}
    }
    return (shortest);
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {throw std::logic_error(NOT_ENOUGH_NUMBS);}
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return (max - min);
}

void Span::printElements() const {
   for (size_t i = 0; i < _numbers.size(); ++i) {
        std::cout << _numbers[i] << " ";
    }
    std::cout << std::endl;
}
