//
// Created by Diana Salamanca on 09-Mar-22.
//

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# define RESET "\033[0m"
# define PURPLE "\033[35;5;95m"
# define ORANGE "\033[38;5;172m"
# define CYAN_L "\033[0;36m"
# define GREEN_L "\033[38;5;28m"

# include <string>

/**
 * Doing forward declaration of 'ICharacter' resolves circular dependency
 * (two or more classes depend on each other).
 * In this case 'AMateria' contains a 'ICharacter' reference.
 */
class ICharacter; // forward declaration

class AMateria {

public:
	AMateria();

	AMateria(std::string const &type);

	AMateria(AMateria const &obj);

	virtual ~AMateria();

	AMateria &operator=(AMateria const &obj);

	virtual AMateria *clone() const = 0; //pure virtual function

	virtual void use(ICharacter &target);

	std::string const &getType() const;

protected:
	std::string const _type;
};

#endif
