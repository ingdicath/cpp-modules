//
// Created by Diana Salamanca on 12/02/2022.
//

#ifndef KAREN_HPP
#define KAREN_HPP
# define RED "\033[0;31m"
# define PURPLE "\033[35;5;95m"
# define CYAN "\033[38;5;81m"
# define RESET "\033[0m"
# define ORANGE "\033[38;5;172m"

# include <iostream>

class Karen {
public:

	Karen();

	~Karen();

	void complain(std::string level);

private:
	void debug();

	void info();

	void warning();

	void error();
};

#endif
