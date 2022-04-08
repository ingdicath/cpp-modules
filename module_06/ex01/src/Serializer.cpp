//
// Created by Diana Salamanca on 24/03/2022.
//

#include "Serializer.hpp"

/**
 * uintptr_t: is an unsigned integer type that is capable of storing a data pointer.
 * reinterpret cast: converts any pointer type to any other pointer type, even of unrelated classes.
 */

uintptr_t serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
