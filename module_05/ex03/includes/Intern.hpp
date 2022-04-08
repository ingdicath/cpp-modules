//
// Created by Diana Salamanca on 16/03/2022.
//

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>
#include <exception>

class Intern {
public:
	Intern();

	Intern(const Intern &obj);

	~Intern();


	Intern &operator=(const Intern &obj);


	AForm *makeForm(const std::string &formName, const std::string &target) const;


	class NonExistenceFormException : public std::exception {
	public:
		const char *what() const throw();
	};

private:
	enum formType {
		SHRUBBERY, ROBOTOMY, PRESIDENTIAL
	};

	static int resolveType(const std::string &formName);
};

#endif
