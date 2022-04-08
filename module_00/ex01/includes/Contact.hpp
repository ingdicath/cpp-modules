//
// Created by Diana catherine Salamanca leguizamon on 2/1/22.
//

#ifndef CONTACT_HPP
# define CONTACT_HPP
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[38;5;81m"
# define RESET "\033[0m"
# define ORANGE "\033[38;5;172m"

# include <iomanip>
# include <iostream>
# include <string>

class Contact {

public:
	std::string getFirstName();

	std::string getLastName();

	std::string getNickName();

	std::string getPhoneNumber();

	std::string getDarkestSecret();

	int getIndexContact() const;

	void setFirstName(const std::string &firstName);

	void setLastName(const std::string &lastName);

	void setNickName(const std::string &nickName);

	void setPhoneNumber(const std::string &phoneNumber);

	void setDarkestSecret(const std::string &darkSecret);

	void setIndexContact(int index);

	Contact();

	~Contact();

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
	int _idContact;
};

#endif