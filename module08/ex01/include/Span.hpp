#pragma once

#include <vector>

class Span {
private:
    std::vector<int> _numbers;
    unsigned int _maxSize;
public:
    Span();
    Span(unsigned int N);
    Span(const Span& other); 
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    template<typename InputIt>
    void addNumbers(InputIt begin, InputIt end) {
        size_t count = std::distance(begin, end);
        if (_numbers.size() + count > _maxSize)
            throw std::runtime_error("Cannot add range: capacity would be exceeded.");
        _numbers.insert(_numbers.end(), begin, end);
    }
};
