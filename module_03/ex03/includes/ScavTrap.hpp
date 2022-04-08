//
// Created by Diana catherine Salamanca leguizamon on 3/3/22.
//

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

/**
 * Using virtual keyword avoid ambiguities for
 * deadly diamond of death. (see multiple inheritance)
 */
class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap(const std::string &name);

	ScavTrap(ScavTrap const &obj);

	~ScavTrap();

	ScavTrap &operator=(ScavTrap const &obj);

	void attack(const std::string &target);

	void attack(ClapTrap &target); //overload attack

	void guardGate();

protected:
	ScavTrap();
};

#endif
