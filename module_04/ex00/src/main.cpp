//
// Created by Diana Salamanca on 06-Mar-22.
//

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <iomanip>

static void printLine() {
	std::cout << std::endl;
	std::cout << std::setfill('*') << std::setw(50) << "*" << std::endl << std::endl;
}

void runNormalAnimalsTest() {
	const Animal *meta = new Animal();
	const Animal *doggy = new Dog();
	const Animal *kitten = new Cat();
	std::cout << "Animal is a " SALMON << doggy->getType() << RESET << std::endl;
	std::cout << "Animal is a " SALMON << kitten->getType() << RESET << std::endl;
	kitten->makeSound(); //will output the cat sound!
	doggy->makeSound();  //will output the dog sound!
	meta->makeSound();  //will output the animal sound!
	delete kitten;
	delete doggy;
	delete meta;
}

void runWrongAnimalsTest() {
	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *kitten = new WrongCat();
	std::cout << "Wrong Animal is a " SALMON << kitten->getType() << RESET << std::endl;
	kitten->makeSound();
	meta->makeSound();
	delete kitten;
	delete meta;
}

int main() {
	runNormalAnimalsTest();
	printLine();
	runWrongAnimalsTest();
	return 0;
}
