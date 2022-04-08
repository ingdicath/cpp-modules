//
// Created by Diana Salamanca on 03/03/2022.
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

/**
 * Virtual functions are functions in the base class that you can override in derived classes.
 * ClapTrap is the base class.
 */
class ClapTrap {
public:

	ClapTrap(const std::string &name);

	ClapTrap(ClapTrap const &obj);

	~ClapTrap();

	ClapTrap &operator=(ClapTrap const &obj);

	virtual void attack(const std::string &target);

	void takeDamage(unsigned int amount);

	void beRepaired(unsigned int amount);

	const std::string &getName() const;

protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

	static void printScore(int a, int b);

	ClapTrap(); // Default constructor cannot be used
};

#endif


