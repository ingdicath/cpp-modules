//
// Created by Diani on 04/03/2022.
//

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
public:
	DiamondTrap(const std::string &name);

	DiamondTrap(DiamondTrap const &obj);

	~DiamondTrap();

	DiamondTrap &operator=(DiamondTrap const &obj);

	void whoAmI();

	using ScavTrap::attack;

private:
	std::string _name;

	DiamondTrap(); // Default constructor cannot be used
};

#endif
