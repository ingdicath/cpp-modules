//
// Created by Diana Salamanca on 28-Mar-22.
//

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# define CYAN_L "\033[0;36m"
# define RESET "\033[0m"

#include <iostream>

template<typename T>
T max(T const &param1, T const &param2) {
	return (param1 > param2 ? param1 : param2);
}

template<typename T>
T min(T const &param1, T const &param2) {
	return (param1 < param2 ? param1 : param2);
}

template<typename T>
void swap(T &param1, T &param2) {
	T temp = param1;
	param1 = param2;
	param2 = temp;
}

#endif
