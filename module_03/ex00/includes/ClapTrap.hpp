//
// Created by Diana Salamanca on 01/03/2022.
//

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define PURPLE "\033[35;5;95m"
# define ORANGE "\033[38;5;172m"
# define CYAN_L "\033[0;36m"
# define SALMON "\033[0;91m"
# define ITALIC "\033[3m"
# define GREEN "\033[38;5;10m"

#include <string>

class ClapTrap {
public:

	ClapTrap(const std::string &name);

	ClapTrap(ClapTrap const &obj);

	~ClapTrap();

	ClapTrap &operator=(ClapTrap const &obj);

	void attack(const std::string &target);

	void takeDamage(unsigned int amount);

	void beRepaired(unsigned int amount);

private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

	ClapTrap(); // Default constructor cannot be used
};

#endif
