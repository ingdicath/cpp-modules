//
// Created by Diana Salamanca on 15/03/2022.
//

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <ostream>
# include <fstream>
# include <string>

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm(const std::string &target);

	ShrubberyCreationForm(const ShrubberyCreationForm &obj);

	~ShrubberyCreationForm();


	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);

private:
	void action() const;

	ShrubberyCreationForm();

};

#endif
