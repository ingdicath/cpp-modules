//
// Created by Diana Salamanca on 10-Mar-22.
//

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# ifndef MAX_SIZE
#  define MAX_SIZE 4
# endif //MAX_SIZE

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();

	MateriaSource(MateriaSource const &obj);

	virtual ~MateriaSource();

	MateriaSource &operator=(MateriaSource const &obj);

	void learnMateria(AMateria *);

	AMateria *createMateria(std::string const &type);

protected:
	AMateria *_inventory[MAX_SIZE];
};

#endif //MATERIASOURCE_HPP
