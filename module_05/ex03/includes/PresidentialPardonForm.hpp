//
// Created by Diana Salamanca on 16/03/2022.
//

#ifndef EX02_PRESIDENTIALPARDONFORM_HPP
#define EX02_PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>
# include <ostream>

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm(const std::string &target);

	PresidentialPardonForm(const PresidentialPardonForm &obj);

	~PresidentialPardonForm();


	PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);

private:
	void action() const;

	PresidentialPardonForm();
};


#endif
