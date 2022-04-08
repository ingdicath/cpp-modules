//
// Created by Diana catherine Salamanca leguizamon on 3/3/22.
//

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap egan("Egan");
	ScavTrap rigo(egan);
	ScavTrap pogacar("Pogacar");
	rigo.attack("Pogacar");
	pogacar.takeDamage(20);
	rigo.attack(pogacar);
	rigo.attack(pogacar);
	rigo.attack(pogacar);
	pogacar.attack(rigo);
	rigo.guardGate();
	rigo.beRepaired(2);
	rigo.attack(pogacar);

	ScavTrap grogu("Grogu");
	ClapTrap luke("Luke");
	grogu.attack(luke);

	ClapTrap queen("Queen");
	ClapTrap megadeath("Megadeath");
	ClapTrap karolG("Karol G");
	ScavTrap badBunny("Bad Bunny");
	megadeath = queen;
	megadeath.attack("Karol G");
	megadeath.attack("Bad Bunny");
	megadeath.attack("Karol G");
	megadeath.attack("Bad Bunny");
	megadeath.attack("Karol G");
	megadeath.attack("Bad Bunny");
	badBunny.takeDamage(5);
	megadeath.attack("Karol G");
	megadeath.attack("Bad Bunny");
	karolG.attack("Queen");
	megadeath.takeDamage(9);
	badBunny.guardGate();
	megadeath.attack("Karol G");
	megadeath.attack("Karol G");
	megadeath.beRepaired(2);

	return 0;
}
