//
// Created by Diani on 19/02/2022.
//

#ifndef FIXED_HPP
# define FIXED_HPP
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define PURPLE "\033[35;5;95m"

# include <iostream>

class Fixed {
public:
	Fixed();

	Fixed(const Fixed &obj);

	Fixed(int const intNumber);

	Fixed(float const floatNumber);

	Fixed &operator=(const Fixed &obj);

	~Fixed();

	float toFloat() const;

	int toInt() const;

	int getRawBits() const;

	void setRawBits(int const raw);

private:
	int _fixedPointNumber;
	static const int _numberFractionalBits = 8;
};

/**
 * Because we don't have access (and are not allowed to) modify std::ostream,
 * you must move this definition outside the class.
 */
std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif
