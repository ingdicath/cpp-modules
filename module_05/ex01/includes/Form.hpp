//
// Created by Diani on 11/03/2022.
//

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat; // forward declaration

class Form {
public:
	Form(const std::string &name, const short &gradeSign, const short &gradeExecute);

	Form(const Form &obj);

	virtual ~Form();

	Form &operator=(const Form &obj);


	const std::string &getName() const;

	bool getIsSigned() const;

	short getGradeSign() const;

	short getGradeExecute() const;


	void beSigned(const Bureaucrat &bureaucrat);


	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw(); //throw() is not a method, is an empty list (no exceptions)
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:

	std::string const _formName;
	bool _isSigned;
	short const _gradeSign;
	short const _gradeExecute;

	Form();
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
