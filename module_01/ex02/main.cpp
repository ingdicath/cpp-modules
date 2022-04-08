//
// Created by Diana Salamanca on 09/02/2022.
//

#include <iostream>
#include <string>

int main() {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "\nMemory address of the string variable->\t" << &string << std::endl;
	std::cout << "Memory address held by stringPTR->\t" << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF->\t" << &stringREF << std::endl;
	std::cout << "\nValue of the string variable->\t\t" << string << std::endl;
	std::cout << "Value pointed to by stringPTR->\t\t" << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF->\t\t" << stringREF << std::endl;
	return 0;
}
