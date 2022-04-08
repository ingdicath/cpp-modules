//
// Created by Diani on 11/03/2022.
//

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(const std::string &name, const short &gradeSign, const short &gradeExecute) : _formName(name),
																						 _isSigned(false),
																						 _gradeSign(gradeSign),
																						 _gradeExecute(gradeExecute) {
	if (gradeSign > MIN_GRADE || gradeExecute > MIN_GRADE) {
		throw Form::GradeTooLowException();
	}
	if (gradeSign < MAX_GRADE || gradeExecute < MAX_GRADE) {
		throw Form::GradeTooHighException();
	}
	std::cout << GREEN "Form '" << _formName
			  << "' was created." RESET << std::endl;
}

Form::Form(const Form &obj) : _formName(obj._formName), _isSigned(obj._isSigned),
							  _gradeSign(obj._gradeSign),
							  _gradeExecute(obj._gradeExecute) {
	std::cout << GREEN "Form '" << _formName
			  << "' was created by copy constructor." RESET << std::endl;
}

Form::~Form() {
	std::cout << RED ITALIC "Form '" << _formName << "' was destroyed." RESET << std::endl;
}


Form &Form::operator=(const Form &obj) {
	if (this != &obj) {
		(void) obj;
	}
	std::cout << GREEN "Form '" << _formName
			  << "' was created by assigment operator." RESET << std::endl;
	return *this;
}


// Grade high 1 - grade low 150
void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (_isSigned) {
		return;
	}
	if (bureaucrat.getGrade() > _gradeSign) {
		throw Bureaucrat::GradeTooLowException();
	}
	_isSigned = true;
}


const std::string &Form::getName() const {
	return _formName;
}

short Form::getGradeSign() const {
	return _gradeSign;
}

short Form::getGradeExecute() const {
	return _gradeExecute;
}

bool Form::getIsSigned() const {
	return _isSigned;
}


const char *Form::GradeTooHighException::what() const throw() {
	return ORANGE "Grade in form is too high. Values must be between 1 and 150." RESET;
}

const char *Form::GradeTooLowException::what() const throw() {
	return ORANGE "Grade in form is too low. Values must be between 1 and 150." RESET;
}


std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form name: " PURPLE << form.getName() << RESET ", signed status: " PURPLE
	   << std::boolalpha << form.getIsSigned()
	   << RESET ", grade to sign: " PURPLE << form.getGradeSign()
	   << RESET ", grade to execute: " PURPLE << form.getGradeExecute() << RESET;
	return os;
}

// Default constructor not used in main
Form::Form() : _gradeSign(0), _gradeExecute(0) {
}
