//
// Created by Diana Salamanca on 09-Mar-22.
//

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <string>
#include <iomanip>
#include <iostream>

static void printLine(const std::string &str) {
	std::cout << std::endl;
	std::cout << std::setfill('*') << std::setw(50) << "*" << std::setfill(' ') << std::endl;
	std::cout << std::setw(30) << std::right << str << std::endl;
	std::cout << std::setfill('*') << std::setw(50) << "*" << std::endl;
}

static void checkLeaks() {
	std::cout << ORANGE "\nChecking for leaks......" RESET << std::endl;
	system("leaks finalfantasy");
}

void runSubjectTest() {
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void runUnequipAndMixTest() {
	IMateriaSource *src = new MateriaSource();
	ICharacter *me = new Character("me");
	ICharacter *bob = new Character("bob");

	src->createMateria("ice"); // he must learn materia before create
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	me->use(3, *bob); // no materia available in this index
	me->use(-1, *bob); // trying to use in index out of range
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice()); //inventory is full

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("bla"); //type unknown
	me->equip(tmp);
	tmp = src->createMateria("ice"); //inventory is full
	me->equip(tmp);

	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	std::cout << GREEN_L "\n~~~ Unequiping ... ~~~" RESET << std::endl;
	AMateria *materia0 = dynamic_cast<Character *>(me)->getInventory(4); //get address index out of range
	me->unequip(4); // try unequip an index out of range
	delete materia0;
	AMateria *materia1 = dynamic_cast<Character *>(me)->getInventory(2); //get address inside range
	me->unequip(2);
	delete materia1;

	std::cout << GREEN_L "\n~~~ Using materias after unequiping ~~~" RESET << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	std::cout << GREEN_L "\n~~~ Equiping in first slot available... ~~~" RESET << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	delete bob;
	delete me;
	delete src;
}

void runDeepCopyTest() {
	ICharacter *grogu = new Character("grogu");
	ICharacter *mando = new Character("mando");
	AMateria *cure = new Cure();
	AMateria *ice = new Ice();

	grogu->equip(cure);
	grogu->use(0, *mando);
	grogu->use(1, *mando); // no materia available in this index
	grogu->equip(ice);
	grogu->use(1, *mando);

	std::cout << GREEN_L "\n~~~ Deep copy: 'evilTwin' creates a copy of 'grogu' ~~~" RESET << std::endl;
	ICharacter *evilTwin = new Character(*(Character *) grogu);
	std::cout << "Address 'evilTwin'\t" << &evilTwin << std::endl;
	std::cout << "Address 'grogu'\t\t" << &grogu << std::endl;

	std::cout << GREEN_L "\n~~~ 'grogu' using materias ~~~" RESET << std::endl;
	grogu->use(0, *mando);
	grogu->use(1, *mando);
	std::cout << GREEN_L "\n~~~ 'evilTwin' using materias ~~~" RESET << std::endl;
	evilTwin->use(0, *mando);
	evilTwin->use(1, *mando);

	std::cout << GREEN_L "\n~~~ After 'grogu' unequiping ... ~~~" RESET << std::endl;
	grogu->unequip(1);
	delete ice;

	std::cout << GREEN_L "\n~~~ 'grogu' using materias after his unequip ~~~" RESET << std::endl;
	grogu->use(0, *mando);
	grogu->use(1, *mando);
	std::cout << GREEN_L "\n~~~ 'evilTwin' using materias after grogu's unequip ~~~" RESET << std::endl;
	evilTwin->use(0, *mando);
	evilTwin->use(1, *mando);

	delete grogu;
	delete evilTwin;
	delete mando;
}

int main() {
	printLine("Subject test");
	runSubjectTest();
	printLine("Unequip & mix");
	runUnequipAndMixTest();
	printLine("Deep copy test");
	runDeepCopyTest();
	checkLeaks();
	return 0;
}
