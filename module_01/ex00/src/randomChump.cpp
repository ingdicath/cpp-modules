//
// Created by Diana Salamanca on 09/02/2022.
//

#include "../includes/Zombie.hpp"

/**
 * - Stack: temporary memory allocation where data members are accessible
 * only if the method that contained them is currently is running.
 * - It allocates or de-allocates the memory automatically as soon as
 * the corresponding method completes its execution.
 * - Stack-memory has less storage space vs. Heap-memory.
 */

void randomChump(std::string name) {
	Zombie zombie;
	zombie.setName(name);
	zombie.announce();
}