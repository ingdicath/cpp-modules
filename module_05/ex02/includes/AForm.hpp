//
// Created by Diani on 11/03/2022.
//

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat; // forward declaration

class AForm {
public:
	AForm(const std::string &name, const short &gradeSign, const short &gradeExecute);

	AForm(const AForm &obj);

	virtual ~AForm();


	AForm &operator=(const AForm &obj);


	const std::string &getName() const;

	const std::string &getTarget() const;

	short getGradeSign() const;

	short getGradeExecute() const;

	bool getIsSigned() const;

	void beSigned(const Bureaucrat &bureaucrat);


	void execute(Bureaucrat const &executor) const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw(); //throw() is not a method, is an empty list (no exceptions)
	};


	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class FormAlreadySignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

protected:
	virtual void action() const = 0; // pure virtual member function
	void setTarget(const std::string& target);

	AForm();

private:
	std::string const _formName;
	std::string _target;
	bool _isSigned;
	short const _gradeSign;
	short const _gradeExecute;

};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
