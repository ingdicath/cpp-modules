//
// Created by Diana catherine Salamanca leguizamon on 3/7/22.
//

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define PURPLE "\033[35;5;95m"
# define SALMON "\033[0;91m"
# define ITALIC "\033[3m"
# define GREEN "\033[38;5;10m"

# include <string>

/**
 * Because makeSound() is not virtual, derived classes will take
 * this function directly from WrongAnimal (base class)
 */

class WrongAnimal {
public:
	WrongAnimal();

	WrongAnimal(WrongAnimal const &obj);

	virtual ~WrongAnimal();

	WrongAnimal &operator=(WrongAnimal const &obj);

	void makeSound() const;

	const std::string &getType() const;

protected:

	WrongAnimal(const std::string& type);

	std::string _type;
};

#endif
