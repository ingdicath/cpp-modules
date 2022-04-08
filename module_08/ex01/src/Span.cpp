//
// Created by Diana Salamanca on  01-Apr-22.
//

#include <iostream>
#include <numeric>
#include "Span.hpp"

Span::Span(unsigned int N) : _n(N) {}

Span::Span(const Span &obj) : _n(obj._n) {
	*this = obj;
}

Span::~Span() {}

Span &Span::operator=(const Span &obj) {
	if (this != &obj) {
		_n = obj._n;
		_myVector = obj._myVector;
	}
	return *this;
}


void Span::addNumber(const int &num) {
	if (_myVector.size() >= _n) {
		throw Span::FullContainerException();
	}
	_myVector.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator current,
					 std::vector<int>::iterator end) {
	while (current != end){
		addNumber(*current++);
	}
}

unsigned int Span::shortestSpan() const {
	int size = static_cast<int>(_myVector.size());
	if (size <= 1) {
		throw Span::NotEnoughItemsSpanException();
	}
	std::vector<int> copy = _myVector;
	std::sort(copy.begin(), copy.end());
	unsigned int shortest = copy.at(1) - copy.at(0);
	for (int i = 0, j = 1; j < size; i++, j++) {
		unsigned int res = copy.at(j) - copy.at(i);
		if (res == 0) {
			return 0;
		} else if (res < shortest) {
			shortest = res;
		}
	}
	return shortest;
}


unsigned int Span::longestSpan() const {
	if (_myVector.size() <= 1) {
		throw Span::NotEnoughItemsSpanException();
	}
	std::vector<int> copy = _myVector;
	std::sort(copy.begin(), copy.end());
	unsigned int longest = copy.at(copy.size() - 1) - copy.at(0);
	return longest;
}

const char *Span::FullContainerException::what() const throw() {
	return SALMON "SpanException: Already full of elements." RESET;
}

const char *Span::NotEnoughItemsSpanException::what() const throw() {
	return SALMON "SpanException: Not enough elements for span." RESET;
}

//Can't be used in main
Span::Span() {}
