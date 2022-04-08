//
// Created by Diana Salamanca on 03/03/2022.
//

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap grogu("Grogu");
	DiamondTrap darthVader("Darth Vader");
	grogu.attack("Darth Vader");
	darthVader.takeDamage(30);
	darthVader.beRepaired(12);
	grogu.highFivesGuys();
	grogu.guardGate();
	grogu.whoAmI();
	grogu.attack(darthVader);
	grogu.attack(darthVader);
	grogu.attack(darthVader);

	DiamondTrap luke("Luke");
	FragTrap palpatine("Palpatine");
	ScavTrap kylo("Kylo");
	ClapTrap trooper("Trooper");
	luke = grogu;
	luke.attack("Palpatine");
	palpatine.takeDamage(30);
	palpatine.highFivesGuys();
	luke.whoAmI();
	kylo.guardGate();
	palpatine.attack("Luke");
	luke.takeDamage(30);
	kylo.attack(luke);
	trooper.attack("Luke");
	luke.attack("Trooper");
	trooper.takeDamage(30);
	luke.attack(kylo);
	luke.attack(kylo);
	luke.attack(kylo);
	luke.attack(kylo);
	luke.attack(palpatine);
	luke.attack(palpatine);
	luke.attack(palpatine);
}
