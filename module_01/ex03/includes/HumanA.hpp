//
// Created by Diana catherine Salamanca leguizamon on 2/10/22.
//

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "../includes/Weapon.hpp"

/**
 * &_weapon retrieve the reference, so it is possible see when a new
 * type of weapon is setting up.
 */

class HumanA {
public:

	HumanA(const std::string &name, Weapon &weapon);

	~HumanA();

	void attack();

private:
	std::string _name;
	Weapon *_weapon;
};

#endif