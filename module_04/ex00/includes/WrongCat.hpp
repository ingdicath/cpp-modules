//
// Created by Diana Salamanca on 07-Mar-22.
//

# ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

/**
 * Function 'makeSound' hides a non-virtual function from class 'WrongAnimal'.
 */

class WrongCat : public WrongAnimal {
public:

	WrongCat();

	WrongCat(const WrongCat &obj);

	virtual ~WrongCat();

	WrongCat &operator=(const WrongCat &obj);

	void makeSound() const;
};


#endif
