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
 * You create an abstract class by declaring at least one pure virtual member function.
 * That's a virtual function declared by using the pure specifier (= 0) syntax.
 */
class AAnimal {
public:
	AAnimal();

	AAnimal(AAnimal const &obj);

	virtual ~AAnimal();

	AAnimal &operator=(AAnimal const &obj);

	virtual void makeSound() const = 0; //pure virtual function. Now class is abstract

	const std::string &getType() const;

protected:

	AAnimal(const std::string &type);

	std::string _type;
};

#endif
