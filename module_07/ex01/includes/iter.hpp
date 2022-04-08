//
// Created by Diana Salamanca on 28/03/2022.
//

#ifndef ITER_HPP
# define ITER_HPP
# define RESET "\033[0m"
# define CYAN_L "\033[0;36m"
# define PURPLE "\033[35;5;95m"

# include <iostream>

template<typename T>
void iter(T const *array, int const len, void (*fun)(T const &)) {
	for (int i = 0; i < len; i++) {
		fun(array[i]);
	}
}

template<typename T>
void print(T const &arg) {
	std::cout << arg << " ";
}

template<typename T>
void printStyle(T const &arg) {
	std::cout << CYAN_L << arg << " " RESET;
}

#endif
