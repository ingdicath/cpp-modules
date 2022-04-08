//
// Created by Diana Salamanca on 09/02/2022.
//

#include "../includes/Zombie.hpp"

/**
 * - Stack memory allocation is considered safer vs. heap memory allocation
 * because the data stored can only be access by owner thread.
 * - Memory allocation and de-allocation is faster vs. Heap-memory allocation.
 * - Stack-memory has less storage space as compared to Heap-memory.
 */

int main() {
	Zombie *heap = newZombie("Mrs. Heap");
	heap->announce();
	delete heap;
	std::cout << std::endl;
	randomChump("Mr. Stack");
	return 0;
}