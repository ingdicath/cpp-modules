//
// Created by Diana Salamanca  on 11/03/2022.
//

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(const std::string &name, const short &gradeSign, const short &gradeExecute) : _formName(name),
																						   _isSigned(false),
																						   _gradeSign(gradeSign),
																						   _gradeExecute(gradeExecute) {
	if (gradeSign > MIN_GRADE || gradeExecute > MIN_GRADE) {
		throw AForm::GradeTooLowException();
	}
	if (gradeSign < MAX_GRADE || gradeExecute < MAX_GRADE) {
		throw AForm::GradeTooHighException();
	}
	std::cout << GREEN "AForm '" << _formName
			  << "' was created." RESET << std::endl;
}

AForm::AForm(const AForm &obj) : _formName(obj._formName), _isSigned(obj._isSigned),
								 _gradeSign(obj._gradeSign),
								 _gradeExecute(obj._gradeExecute) {
	std::cout << GREEN "AForm '" << _formName
			  << "' was created by copy constructor." RESET << std::endl;
}

AForm::~AForm() {
	std::cout << RED ITALIC "AForm '" << _formName << "' was destroyed." RESET << std::endl;
}


AForm &AForm::operator=(const AForm &obj) {
	if (this != &obj) {
		(void) obj;
	}
	std::cout << GREEN "AForm '" << _formName
			  << "' was created by assigment operator." RESET << std::endl;
	return *this;
}


// Grade high 1 - grade low 150
void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (_isSigned) {
		throw AForm::FormAlreadySignedException();
	}
	if (bureaucrat.getGrade() > _gradeSign) {
		throw Bureaucrat::GradeTooLowException();
	}
	_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!_isSigned) {
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > _gradeExecute) {
		throw Bureaucrat::GradeTooLowException();
	}
	action();
}


const std::string &AForm::getName() const {
	return _formName;
}

const std::string &AForm::getTarget() const {
	return _target;
}

short AForm::getGradeSign() const {
	return _gradeSign;
}

short AForm::getGradeExecute() const {
	return _gradeExecute;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

void AForm::setTarget(const std::string &target) {
	_target = target;
}


const char *AForm::GradeTooHighException::what() const throw() {
	return ORANGE "Grade in form is too high. Values must be between 1 and 150." RESET;
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ORANGE "Grade in form is too low. Values must be between 1 and 150." RESET;
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ORANGE "Form hasn't signed yet." RESET;
}

const char *AForm::FormAlreadySignedException::what() const throw() {
	return ORANGE "Form was already signed." RESET;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "AForm name: " PURPLE << form.getName() << RESET ", signed status: " PURPLE
	   << std::boolalpha << form.getIsSigned()
	   << RESET ", grade to sign: " PURPLE << form.getGradeSign()
	   << RESET ", grade to execute: " PURPLE << form.getGradeExecute() << RESET;
	return os;
}

std::ostream &operator<<(std::ostream &os, AForm *form) {
	os << "AForm name: " PURPLE << form->getName() << RESET ", signed status: " PURPLE
	   << std::boolalpha << form->getIsSigned()
	   << RESET ", grade to sign: " PURPLE << form->getGradeSign()
	   << RESET ", grade to execute: " PURPLE << form->getGradeExecute() << RESET;
	return os;
}

// Default constructor not used in main
AForm::AForm() : _gradeSign(0), _gradeExecute(0) {
}
