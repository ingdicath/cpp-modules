//
// Created by Diana Salamanca on 09/02/2022.
//

#include "../includes/Zombie.hpp"

/**
 * - Heap memory: no automatic de-allocation is provided.
 * - The processing time(Accessing time) of this memory is quite slow vs. Stack.
 * - Size of Heap-memory is quite larger vs. Stack-memory.
 */

Zombie *newZombie(std::string name) {
	Zombie *zombie = new Zombie();
	zombie->setName(name);
	return zombie;
}
