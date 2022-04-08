//
// Created by Diana Salamanca on 03/04/2022.
//

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
# define RESET "\033[0m"
# define PURPLE "\033[35;5;95m"
# define CYAN_L "\033[0;36m"
# define GREEN "\033[38;5;10m"

#include <stack>
#include <deque>
#include <iostream>

/**
 * By default, if no container class is specified for a particular stack class instantiation,
 * the standard container deque is used.
 */
template<typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() : std::stack<T>() {}

	MutantStack(MutantStack<T> const &obj) : std::stack<T>() {
		*this = obj;
	}

	virtual ~MutantStack() {}


	MutantStack &operator=(MutantStack<T> const &obj) {
		if (this != &obj) {
			std::stack<T>::operator=(obj);
		}
		return *this;
	}

	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::reverse_iterator reverseIterator; // no const, is C++11

	iterator begin() {
		return this->c.begin(); // c is the 'container_type' from stack class
	}

	iterator end() {
		return this->c.end();
	}

	reverseIterator rbegin() {
		return this->c.rbegin();
	}

	reverseIterator rend() {
		return this->c.rend();
	}

};

#endif
