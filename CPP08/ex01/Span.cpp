#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <climits>
#include <iterator>

Span::Span(unsigned int n) : _maxSize(n) {}
void Span::addNumber(int number) {
	if (_numbers.size() >= _maxSize) {
		throw std::length_error("Span is full");
	}
	_numbers.push_back(number);
}

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
	if (std::distance(begin, end) + _numbers.size() > _maxSize) {
		throw std::length_error("Span will exceed maximum size");
	}
	_numbers.insert(_numbers.end(), begin, end);
}

unsigned int Span::shortestSpan() const {
	if (_numbers.size() < 2) {
		throw std::logic_error("Not enough numbers to find a span");
	}
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	unsigned int minSpan = UINT_MAX;
	for (size_t i = 1; i < sorted.size(); ++i) {
		minSpan = std::min(minSpan, static_cast<unsigned int>(sorted[i] - sorted[i - 1]));
	}
	return minSpan;
}

unsigned int Span::longestSpan() const {
	if (_numbers.size() < 2) {
		throw std::logic_error("Not enough numbers to find a span");
	}
	int minValue = *std::min_element(_numbers.begin(), _numbers.end());
	int maxValue = *std::max_element(_numbers.begin(), _numbers.end());
	if (minValue == maxValue) {
		return 0;
	}
	return static_cast<unsigned int>(maxValue - minValue);
}
