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
	void addRange(Iterator begin, Iterator end);
	unsigned int shortestSpan() const ;

	unsigned int longestSpan() const;
};
#endif
