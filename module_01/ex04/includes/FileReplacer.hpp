//
// Created by Diana catherine Salamanca leguizamon on 11-Feb-22.
//

#ifndef FILE_HPP
# define FILE_HPP
# define RESET "\033[0m"
# define RED "\033[0;31m"

# include <iostream>
# include <string>
# include <fstream>

class FileReplacer {
public:
	FileReplacer(const std::string &fileName);

	~FileReplacer();

	void replace(const std::string &str1, const std::string &str2);

private:
	static void replaceString(std::string *line, size_t pos, size_t len,
							  const std::string &str2);

	std::ifstream _srcFile;
	std::ofstream _dstFile;
};

#endif
