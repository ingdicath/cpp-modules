//
// Created by Diana Salamanca on 03/03/2022.
//

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap : public ClapTrap {
public:
	FragTrap(const std::string &name);

	FragTrap(FragTrap const &obj);

	~FragTrap();

	FragTrap &operator=(FragTrap const &obj);

	void highFivesGuys();

private:
	FragTrap(); // Default constructor cannot be used
};

#endif
