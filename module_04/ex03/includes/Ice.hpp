//
// Created by Diana Salamanca on 09-Mar-22.
//

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {
public:
	Ice();

	Ice(Ice const &obj);

	virtual ~Ice();

	Ice &operator=(Ice const &obj);

	AMateria *clone() const;

	void use(ICharacter &target);
};

#endif
