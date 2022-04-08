//
// Created by Diani on 18/02/2022.
//

#ifndef FIXED_HPP
# define FIXED_HPP
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define PURPLE "\033[35;5;95m"

class Fixed {
public:
	Fixed();

	Fixed(Fixed const &obj);

	Fixed &operator=(Fixed const &obj);

	~Fixed();

	int getRawBits() const;

	void setRawBits(int const raw);

private:
	int _fixedPointNumber;
	static const int _numberFractionalBits = 8;
};

#endif
