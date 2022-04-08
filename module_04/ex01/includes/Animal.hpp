//
// Created by Diana Salamanca on 06-Mar-22.
//

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define PURPLE "\033[35;5;95m"
# define SALMON "\033[0;91m"
# define CYAN_L "\033[0;36m"
# define ITALIC "\033[3m"
# define GREEN "\033[38;5;10m"

# include <string>

/**
 * Using virtual in the destructor, allows to clean both base and derived classes.
 * Virtual functions are functions in the base class that you can override in derived classes.
 */
class Animal {
public:
	Animal();

	Animal(Animal const &obj);

	virtual ~Animal();

	Animal &operator=(Animal const &obj);

	virtual void makeSound() const;

	const std::string &getType() const;

protected:

	Animal(const std::string &type);

	std::string _type;
};

#endif
