//
// Created by Diana Salamanca on 09-Mar-22.
//

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# define ORANGE "\033[38;5;172m"
# define CYAN_L "\033[0;36m"
# define MAX_SIZE 4

# include "ICharacter.hpp"
# include <string>

class Character : public ICharacter {
public:

	Character(const std::string &name);

	Character(Character const &obj);

	virtual ~Character();

	Character &operator=(Character const &obj);

	const std::string &getName() const;

	virtual void equip(AMateria *materia);

	virtual void unequip(int index);

	virtual void use(int index, ICharacter &target);

	AMateria *getInventory(unsigned int index) const;

private:
	AMateria *_inventory[MAX_SIZE];
	std::string _name;

	Character();
};

#endif
