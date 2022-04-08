//
// Created by Diani on 01/04/2022.
//

#ifndef SPAN_HPP
# define SPAN_HPP
# define RESET "\033[0m"
# define PURPLE "\033[35;5;95m"
# define SALMON "\033[0;91m"
# define GREEN "\033[38;5;10m"

#include <exception>
#include <vector>

class Span {
public:
	Span(unsigned int N);

	Span(Span const &obj);

	virtual ~Span();


	Span &operator=(Span const &obj);


	void addNumber(int const &num);

	void addNumber(std::vector<int>::iterator current, std::vector<int>::iterator end);

	unsigned int shortestSpan() const;

	unsigned int longestSpan() const;


	// Nested class for exception
	class FullContainerException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class NotEnoughItemsSpanException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	unsigned int _n;
	std::vector<int> _myVector;

	Span();

};

#endif
