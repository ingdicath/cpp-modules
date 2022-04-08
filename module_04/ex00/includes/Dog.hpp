//
// Created by Diana Salamanca on 06-Mar-22.
//

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
public:

	Dog();

	Dog(const Dog &obj);

	virtual ~Dog();

	Dog &operator=(const Dog &obj);

	void makeSound() const;
};

#endif
