//
// Created by Diana Salamanca on 09/02/2022.
//

#include "../includes/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name){
	Zombie *zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++){
		zombieHorde[i].setName(name);
	}
	return zombieHorde;
}