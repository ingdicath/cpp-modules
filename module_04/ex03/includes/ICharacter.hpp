//
// Created by Diana Salamanca on 09-Mar-22.
//

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>

/**
 * Doing forward declaration of AMateria' resolves circular dependency
 * (two or more classes depend on each other).
 * In this case 'ICharacter' contains a 'AMateria' pointer.
 */
class AMateria; //forward declaration

class ICharacter {
public:
	virtual ~ICharacter() {}

	virtual std::string const &getName() const = 0;

	virtual void equip(AMateria *m) = 0;

	virtual void unequip(int index) = 0;

	virtual void use(int index, ICharacter &target) = 0;
};

#endif
