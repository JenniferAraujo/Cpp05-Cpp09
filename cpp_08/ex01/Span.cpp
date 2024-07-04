#include "Span.hpp"

Span::Span(): _maxInt(0) {}

Span::Span(unsigned int N): _maxInt(N) {}

Span::Span(const Span& copy) {
	_maxInt = copy._maxInt;
	_numbers = copy._numbers;
}

Span& Span::operator= (const Span& copy){
	if (this == &copy)
		return *this;
	_maxInt = copy._maxInt;
	_numbers = copy._numbers;
	return *this;
}

void	Span::addNumber(int num) {
	if (_numbers.size() >= _maxInt) {
		throw std::overflow_error("Exceeded maximum size of Span");
	}
	_numbers.push_back(num);
}

int	Span::shortestSpan(void) {
	if (_numbers.size() < 2) {
		throw std::logic_error("Cannot find span with less than 2 numbers");
	}
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int	Span::longestSpan(void) {
	if (_numbers.size() < 2)
		throw std::logic_error("Cannot find span with less than 2 numbers");
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return max - min;
}

void	Span::addNUmber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_numbers.size() + std::distance(begin, end) > _maxInt) {
		throw std::overflow_error("Exceeded maximum size of Span");
	}
	_numbers.insert(_numbers.end(), begin, end);
}

Span::~Span(){}