//
// Created by Diana Salamanca on 03/03/2022.
//

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap luke("Luke");
	ScavTrap darthVader("Darth Vader");
	FragTrap grogu("Grogu");
	grogu.highFivesGuys();
	grogu.attack("Luke");
	luke.takeDamage(30);
	grogu.highFivesGuys();
	darthVader.guardGate();
	darthVader.attack(grogu);
	grogu.attack("Darth Vader");
	darthVader.takeDamage(30);
	grogu.attack("Darth Vader");
	darthVader.takeDamage(30);
	grogu.attack("Darth Vader");
	darthVader.takeDamage(30);
	grogu.attack("Darth Vader");
	darthVader.takeDamage(30);

	FragTrap homer("Homer");
	FragTrap bart("Bart");
	FragTrap lisa(bart);
	lisa.attack("Homer");
	homer.takeDamage(30);
	lisa.highFivesGuys();
	lisa.attack("Homer");
	homer.takeDamage(30);
	lisa.attack("Homer");
	homer.takeDamage(30);
	homer.beRepaired(15);
	lisa.attack("Homer");
	homer.takeDamage(30);
	return 0;
}
