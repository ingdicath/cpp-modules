//
// Created by Diana Salamanca on 03/03/2022.
//

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

/**
 * Using virtual keyword avoid ambiguities for
 * deadly diamond of death. (see multiple inheritance)
 */
class FragTrap : virtual public ClapTrap {
public:
	FragTrap(const std::string &name);

	FragTrap(FragTrap const &obj);

	~FragTrap();

	FragTrap &operator=(FragTrap const &obj);

	void highFivesGuys();

protected:
	FragTrap();
};

#endif
