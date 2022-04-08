//
// Created by Diana Salamanca on 09/02/2022.
//

#include "../includes/Zombie.hpp"

int main() {
	int num = 10;
	Zombie *zombies = zombieHorde(num, "Pajarito malo");
	for (int i = 0; i < num; i++) {
		zombies[i].announce();
	}
	delete [] zombies;
	return 0;
}
