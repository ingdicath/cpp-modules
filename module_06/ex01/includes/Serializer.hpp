//
// Created by Diana Salamanca on 24/03/2022.
//

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define CYAN_L "\033[0;36m"

# include <string>
# include <cstdint>

typedef struct s_Data {
	std::string name;
	int age;
	int weight;
} Data;

uintptr_t serialize(Data *ptr);

Data *deserialize(uintptr_t raw);

#endif
