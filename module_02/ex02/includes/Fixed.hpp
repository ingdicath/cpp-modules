//
// Created by Diana catherine Salamanca leguizamon on 2/24/22.
//

#ifndef FIXED_HPP
# define FIXED_HPP
# define RESET "\033[0m"
# define PURPLE "\033[35;5;95m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[38;5;10m"
# define ORANGE "\033[38;5;172m"
# define CYAN "\033[38;5;81m"
# define GRAY "\033[37m"

# include <iostream>

class Fixed {
public:

	// Constructors and destructor.
	Fixed();

	Fixed(Fixed const &obj);

	Fixed(int const intNumber);

	Fixed(float const floatNumber);

	~Fixed();

	// Overloaded assignment operator.
	Fixed &operator=(Fixed const &obj);


	// Overloaded comparison operators.
	bool operator>(Fixed const &obj) const;

	bool operator<(Fixed const &obj) const;

	bool operator>=(Fixed const &obj) const;

	bool operator<=(Fixed const &obj) const;

	bool operator==(Fixed const &obj) const;

	bool operator!=(Fixed const &obj) const;


	// Overloaded arithmetic operators.
	Fixed operator+(Fixed const &obj) const;

	Fixed operator-(Fixed const &obj) const;

	Fixed operator*(Fixed const &obj) const;

	Fixed operator/(Fixed const &obj) const;


	// Overloaded increment/decrement operators.
	Fixed &operator++();

	Fixed operator++(int);

	Fixed &operator--();

	Fixed operator--(int);


	// Overloaded member functions min & max.
	static Fixed &min(Fixed &num1, Fixed &num2);

	static const Fixed &min(Fixed const &num1, Fixed const &num2);

	static Fixed &max(Fixed &num1, Fixed &num2);

	static const Fixed &max(Fixed const &num1, Fixed const &num2);


	// Converter member functions.
	float toFloat() const;

	int toInt() const;


	// Getter and setter.
	int getRawBits() const;

	void setRawBits(int const raw);

private:
	int _fixedPointNumber;
	static const int _numberFractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif
