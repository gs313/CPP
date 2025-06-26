#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>
class Span {
private:
	std::vector<int> _numbers;
	unsigned int _maxSize;
public:
	Span(unsigned int n);

	void addNumber(int number);

	template <typename Iterator>
	void addRange(Iterator begin, Iterator end)
	{
			if (std::distance(begin, end) + _numbers.size() > _maxSize) {
				throw std::length_error("Span will exceed maximum size");
			}
			_numbers.insert(_numbers.end(), begin, end);
	}
	unsigned int shortestSpan() const ;

	unsigned int longestSpan() const;
};
#endif
