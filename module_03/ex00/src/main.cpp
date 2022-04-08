//
// Created by Diana Salamanca on 01/03/2022.
//

#include "ClapTrap.hpp"

int main() {
	ClapTrap ironMaiden("Iron Maiden");
	ironMaiden.attack("Maluma");
	ironMaiden.takeDamage(5);
	ironMaiden.beRepaired(4);
	ironMaiden.takeDamage(2);
	ironMaiden.beRepaired(7);
	ironMaiden.takeDamage(15);

	ClapTrap acdc("ACDC");
	ClapTrap kiss(acdc);
	kiss.attack("Bad Bunny");
	kiss.takeDamage(5);
	kiss.attack("Karol G");
	kiss.takeDamage(2);
	kiss.attack("J Balvin");
	kiss.takeDamage(3);

	ClapTrap beatles("The beatles");
	beatles.attack("Bad Bunny");
	beatles.takeDamage(5);
	beatles.attack("Karol G");
	beatles.takeDamage(2);
	beatles.attack("J Balvin");
	beatles.takeDamage(2);
	beatles.beRepaired(4);
	beatles.attack("Karol G");
	beatles.takeDamage(2);
	beatles.beRepaired(3);
	beatles.attack("J Balvin");
	beatles.takeDamage(2);
	beatles.beRepaired(3);
	beatles.attack("Daddy Yankee");
	beatles.takeDamage(2);
	beatles.beRepaired(3);
	beatles.attack("Maluma");
	return 0;
}
