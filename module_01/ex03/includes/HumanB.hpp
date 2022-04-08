//
// Created by Diana catherine Salamanca leguizamon on 2/10/22.
//

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "../includes/Weapon.hpp"

class HumanB {
public:
	HumanB(const std::string &name);

	~HumanB();

	void attack();

	void setWeapon(Weapon &weapon);

private:
	std::string _name;
	Weapon *_weapon;
};

#endif
