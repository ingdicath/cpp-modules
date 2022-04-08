//
// Created by Diani on 31/03/2022.
//

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
# define RESET "\033[0m"
# define PURPLE "\033[35;5;95m"
# define SALMON "\033[0;91m"
# define GREEN "\033[38;5;10m"

#include <iostream>
#include <algorithm>
#include <exception>

class NotFoundException : public std::exception {
public:
	virtual const char *what() const throw() {
		return SALMON "Integer not found in container." RESET;
	}
};

/**
 * begin(): Returns an iterator pointing to the first element in the container.
 * end(): Returns an iterator referring to the past-the-end element in the container.
 * The past-the-end element is the theoretical element that would follow
 * the last element in the container.
 */
template<typename T>
typename T::iterator easyfind(T &container, int const &toFind) {
	typename T::iterator iter;
	iter = std::find(container.begin(), container.end(), toFind);
	if (iter == container.end()) {
		throw NotFoundException();
	}
	return iter;
}

template<typename T>
void printContainer(T const &container) {
	std::cout << "Elements in container are: ";
	typename T::const_iterator iter;
	for (iter = container.begin(); iter != container.end(); iter++){
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

#endif
