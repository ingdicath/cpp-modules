//
// Created by Diana catherine Salamanca leguizamon on 2/10/22.
//

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

int main() {
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("Amban phase-pulse blaster");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType(("Amban phase-pulse blaster"));
		jim.attack();
	}
	return 0;
}
