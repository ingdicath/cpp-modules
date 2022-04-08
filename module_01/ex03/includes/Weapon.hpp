//
// Created by Diana catherine Salamanca leguizamon on 2/10/22.
//

#ifndef WEAPON_HPP
# define WEAPON_HPP
# define CYAN "\033[38;5;81m"
# define PURPLE "\033[35;5;95m"
# define RESET "\033[0m"

# include <iostream>
# include <string>

class Weapon {
public:
	Weapon(const std::string &type);

	~Weapon();

	const std::string &getType() const;

	void setType(const std::string &type);

private:
	std::string _type;
};

#endif
