//
// Created by Diana Salamanca on 07-Mar-22.
//

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
public:

	Cat();

	Cat(const Cat &obj);

	virtual ~Cat();

	Cat &operator=(const Cat &obj);

	void makeSound() const;

	Brain *getBrain() const;

private:
	Brain *_brain;

};

#endif
