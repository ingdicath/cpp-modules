//
// Created by Diana Salamanca on 06-Mar-22.
//

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
public:

	Dog();

	Dog(const Dog &obj);

	virtual ~Dog();

	Dog &operator=(const Dog &obj);

	void makeSound() const;

	Brain *getBrain() const;

private:
	Brain *_brain;
};

#endif
