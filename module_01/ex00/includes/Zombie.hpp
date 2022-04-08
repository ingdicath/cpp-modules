//
// Created by Diana Salamanca on 09/02/2022.
//

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# define RESET "\033[0m"
# define RED "\033[0;31m"

# include <iostream>

class Zombie {
public:
	void setName(const std::string &name);

	void announce();

	Zombie();

	~Zombie();

private:
	std::string _name;
};

Zombie *newZombie(std::string name);

void randomChump(std::string name);

#endif
