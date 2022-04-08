//
// Created by Diana Salamanca on 06-Mar-22.
//

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>
#include <iomanip>

static void printLine(const std::string &str) {
	std::cout << std::endl;
	std::cout << std::setfill('*') << std::setw(50) << "*" << std::setfill(' ') << std::endl;
	std::cout << std::setw(30) << std::right << str << std::endl;
	std::cout << std::setfill('*') << std::setw(50) << "*" << std::endl;
}

static void checkLeaks() {
	std::cout << SALMON "\nChecking for leaks......" RESET << std::endl;
	system("leaks brain");
}

void runSubjectTest() {
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j;//should not create a leak
	delete i;
}

void runArrayAnimalTest() {
	const int size = 4;
	Animal *animals[size];

	// Create animals array
	for (int i = 0; i < size; i++) {
		if (i < (size / 2)) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}
	// Print animal type
	for (int i = 0; i < size; i++) {
		std::cout << "I am a " << animals[i]->getType() << std::endl;
	}
	// Clean animals
	for (int i = 0; i < size; i++) {
		delete animals[i];
	}
}

void runDogDeepCopyTest() {
	unsigned int pos = 39;
	Dog *dog1 = new Dog();
	dog1->getBrain()->setIdea(pos, "I want grilled chicken");

	// When the data will be copied then all the resources will also get
	// allocated to the new object.
	Dog *dog2 = new Dog(*dog1);

	std::cout << "Value pointer dog1\t\t" << dog1 << std::endl;
	std::cout << "Address variable dog1\t\t" << &dog1 << std::endl;
	std::cout << "Address dog1->brain\t\t" << dog1->getBrain() << std::endl;
	std::cout << "Address dog1->brain->ideas\t" << dog1->getBrain()->getIdeas() << std::endl;
	std::cout << "Value dog1->brain->ideas[POS]\t" << PURPLE << dog1->getBrain()->getIdeas()[pos];
	std::cout << RESET << std::endl << std::endl;

	std::cout << "Value pointer dog2\t\t" << dog2 << std::endl;
	std::cout << "Address variable dog2\t\t" << &dog2 << std::endl;
	std::cout << "Address dog2->brain\t\t" << dog2->getBrain() << std::endl;
	std::cout << "Address dog2->brain->ideas\t" << dog2->getBrain()->getIdeas() << std::endl;
	std::cout << "Value dog2->brain->ideas[POS]\t" << PURPLE << dog2->getBrain()->getIdeas()[pos];
	std::cout << std::endl << RESET << std::endl;

	dog1->getBrain()->setIdea(pos, "I want sushi");
	std::cout << CYAN_L "After change value in dog1 ideas[POS]" RESET << std::endl;
	std::cout << "Value dog1->brain->ideas[POS]\t" << PURPLE << dog1->getBrain()->getIdeas()[pos];
	std::cout << RESET << std::endl;
	std::cout << "Value dog2->brain->ideas[POS]\t" << PURPLE << dog2->getBrain()->getIdeas()[pos];
	std::cout << RESET << std::endl;

	delete dog1;
	delete dog2;
}

void runCatDeepCopyTest() {
	unsigned int pos = 0;
	Cat *cat1 = new Cat();
	cat1->getBrain()->setIdea(pos, "Mrrrrr ouch");
	Cat *cat2 = new Cat(*cat1);

	std::cout << "Value pointer cat1\t\t" << cat1 << std::endl;
	std::cout << "Address variable cat1\t\t" << &cat1 << std::endl;
	std::cout << "Address cat1->brain\t\t" << cat1->getBrain() << std::endl;
	std::cout << "Address cat1->brain->ideas\t" << cat1->getBrain()->getIdeas() << std::endl;
	std::cout << "Value cat1->brain->ideas[POS]\t" << PURPLE << cat1->getBrain()->getIdeas()[pos];
	std::cout << RESET << std::endl << std::endl;

	std::cout << "Value pointer cat2\t\t" << cat2 << std::endl;
	std::cout << "Address variable cat2\t\t" << &cat2 << std::endl;
	std::cout << "Address cat2->brain\t\t" << cat2->getBrain() << std::endl;
	std::cout << "Address cat2->brain->ideas\t" << cat2->getBrain()->getIdeas() << std::endl;
	std::cout << "Value cat2->brain->ideas[POS]\t" << PURPLE << cat2->getBrain()->getIdeas()[pos];
	std::cout << std::endl << RESET << std::endl;

	cat1->getBrain()->setIdea(0, "Ahhhhhh");
	std::cout << CYAN_L "After change value in cat1 ideas[POS]" RESET << std::endl;
	std::cout << "Value cat1->brain->ideas[POS]\t" << PURPLE << cat1->getBrain()->getIdeas()[pos];
	std::cout << RESET << std::endl;
	std::cout << "Value cat2->brain->ideas[POS]\t" << PURPLE << cat2->getBrain()->getIdeas()[pos];
	std::cout << RESET << std::endl;

	delete cat1;
	delete cat2;
}

int main() {
	printLine("Subject test");
	runSubjectTest();
	printLine("Animal array test");
	runArrayAnimalTest();
	printLine("Deep copy test DOG");
	runDogDeepCopyTest();
	printLine("Deep copy test CAT");
	runCatDeepCopyTest();
	checkLeaks();
	return 0;
}
