//
// Created by Diana Salamanca on 25/03/2022.
//

#include "Serializer.hpp"
#include <iostream>

static void printRes(const std::string &str1, const std::string &str2, int num1, int num2, Data *data) {
	std::cout <<  str1 << " name: " CYAN_L << str2
			  << RESET ", age " CYAN_L << num1 
			  << RESET ", weight " CYAN_L << num2
			  << RESET", address: " CYAN_L << data << RESET << std::endl;
}

int main() {
	Data *original = new Data;
	original->name = "Diana";
	original->age = 15;
	original->weight = 55;

	uintptr_t raw = serialize(original);
	Data *final = deserialize(raw);

	if (original != final) {
		std::cerr << RED "Answers are not identical" RESET << std::endl;
		delete original;
		return (EXIT_FAILURE);
	}

	printRes("Original->     ", original->name, original->age, original->weight, original);
	printRes( "Deserialized-> ",final->name, final->age, final->weight, final);

	std::cout << std::endl;
	std::cout << "Serialize->    " << raw << std::endl;
	std::cout << "Deserialize->  " << final << std::endl;
	delete original;
	return 0;
}
