//
// Created by Diana Salamanca on 11/03/2022.
//

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# define RED "\033[0;31m"
# define RESET "\033[0m"
# define ORANGE "\033[38;5;172m"
# define CYAN_L "\033[0;36m"
# define ITALIC "\033[3m"
# define GREEN "\033[38;5;10m"
# define PURPLE "\033[35;5;95m"
# define MIN_GRADE 150
# define MAX_GRADE 1

#include <string>
#include <ostream>
#include <stdexcept>

class Bureaucrat {
public:
	Bureaucrat(const std::string &name, short grade);

	Bureaucrat(const Bureaucrat &obj);

	virtual ~Bureaucrat();


	Bureaucrat &operator=(const Bureaucrat &obj);


	const std::string &getName() const;

	unsigned int getGrade() const;


	void incrementGrade();

	void decrementGrade();


	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw(); //throw() is not a method, is an empty list (no exceptions)
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	std::string const _name;
	short _grade;

	Bureaucrat();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
