//
// Created by Diana catherine Salamanca leguizamon on 11-Feb-22.
//

#include "../includes/FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string &fileName) {
	this->_srcFile.open(fileName);
	if (!this->_srcFile.is_open()) {
		std::cout << RED << std::strerror(errno) << RESET << std::endl;
		return;
	}
	this->_dstFile.open(fileName + ".replace");
	if (!this->_dstFile.is_open()) {
		std::cout << RED << std::strerror(errno) << RESET << std::endl;
		return;
	}
}

FileReplacer::~FileReplacer() {
	this->_srcFile.close();
	this->_dstFile.close();
}

void FileReplacer::replaceString(std::string *line, size_t pos, size_t len,
								 const std::string &str2) {
	line->erase(pos, len);
	line->insert(pos, str2);
}

/**
 * ofstream: write on files, ifstream: read from files
 * fstream: read and write from/to files
 * string::npos: means until the end of the string.
 * string::find: finds the index of the first match
 */

void FileReplacer::replace(const std::string &str1, const std::string &str2) {
	std::string newLine;
	size_t len = str1.length();

	while (std::getline(this->_srcFile, newLine)) {
		size_t pos = newLine.find(str1);
		while (pos != std::string::npos) {
			replaceString(&newLine, pos, len, str2);
			pos = newLine.find(str1, pos + str2.length()); //update pos, looking for str1 in the same line
		}
		this->_dstFile << newLine << std::endl;
	}
}
