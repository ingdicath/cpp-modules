//
// Created by Diana Salamanca on 07/03/2022.
//

#ifndef BRAIN_HPP
# define BRAIN_HPP
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define PURPLE "\033[35;5;95m"
# define SALMON "\033[0;91m"
# define ITALIC "\033[3m"
# define GREEN "\033[38;5;10m"
# define NUM_IDEAS 100

# include <string>

class Brain {
public:
	Brain();

	Brain(const Brain &obj);

	virtual ~Brain();

	Brain &operator=(const Brain &obj);

	const std::string *getIdeas() const;

	void setIdea(unsigned int pos, const std::string &idea);

private:
	std::string _ideas[NUM_IDEAS];
};

#endif
