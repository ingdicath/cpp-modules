//
// Created by Diana Salamanca on 16/03/2022.
//

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>
# include <ostream>

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(const std::string &target);

	RobotomyRequestForm(const RobotomyRequestForm &obj);

	~RobotomyRequestForm();


	RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);

private:
	void action() const;

	RobotomyRequestForm();

};

#endif
