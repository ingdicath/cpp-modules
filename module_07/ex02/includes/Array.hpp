//
// Created by Diana Salamanca on 29/03/2022.
//

#ifndef ARRAY_HPP
#define ARRAY_HPP
# define RESET "\033[0m"
# define PURPLE "\033[35;5;95m"
# define SALMON "\033[0;91m"
# define GREEN "\033[38;5;10m"

#include <iostream>

template<typename T>
class Array {
public:
	Array<T>() : _size(0), _array(NULL) {}

	Array(unsigned int n) : _size(n), _array(new T[_size]()) {}

	Array<T>(Array<T> const &obj) : _size(obj._size), _array(new T[obj._size]()) {
		for (unsigned int i = 0; i < obj._size; i++) {
			_array[i] = obj._array[i];
		}
	}

	~Array<T>() {
		delete[] _array;
	}


	Array<T> &operator=(const Array<T> &obj) {
		if (this != &obj) {
			delete[] _array;
			_size = obj._size;
			_array = new T[obj._size]();
			for (unsigned int i = 0; i < obj._size; i++) {
				_array[i] = obj._array[i];
			}
		}
		return *this;
	}

	// for overload << operator
	T *getArray() const {
		return _array;
	}

	unsigned int size() const {
		return _size;
	}


	// Nested class for exception
	class OutofBoundException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return SALMON "Index is out of bounds." RESET;
		}
	};


	// Overloading Subscript or array index operator []
	T &operator[](unsigned int index) {
		if (index >= _size) {
			throw OutofBoundException();
		}
		return _array[index];
	}


private:
	unsigned int _size;
	T *_array;
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &a) {
	for (unsigned int i = 0; i < a.size(); i++) {
		os << a.getArray()[i] << " ";
	}
	return os;
}

#endif
