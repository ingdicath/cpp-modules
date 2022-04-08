//
// Created by Diana catherine Salamanca leguizamon on 10-Feb-22.
//

# include "../includes/FileReplacer.hpp"

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << RED << "Args must be 3: <filename> "
				  << "<string 1> <string 2>" << RESET << std::endl;
		return 1;
	}
	std::string fileName = argv[1];
	std::string str1 = argv[2];
	std::string str2 = argv[3];
	if (str1.empty() || str2.empty()) {
		std::cerr << RED << "Args can't be empty strings." << RESET << std::endl;
		return 1;
	}
	FileReplacer replacer(fileName);
	replacer.replace(str1, str2);
	return 0;
}
