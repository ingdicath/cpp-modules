//
// Created by Diana Salamanca on 09-Mar-22.
//

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
public:
	Cure();

	Cure(Cure const &obj);

	virtual ~Cure();

	Cure &operator=(Cure const &obj);

	AMateria *clone() const;

	void use(ICharacter &target);
};

#endif
