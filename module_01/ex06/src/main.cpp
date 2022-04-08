//
// Created by Diana Salamanca on 18/02/2022.
//

#include "../includes/Karen.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED << "Wrong argument. It must be <DEBUG> or <INFO> or "
				  << "<WARNING> or <ERROR>." << RESET << std::endl;
		return 1;
	}
	std::string level = argv[1];
	Karen karen;
	karen.complain(level);
	return 0;
}
