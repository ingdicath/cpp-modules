//
// Created by Diana catherine Salamanca leguizamon on 2/1/22.
//

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# define ADD "ADD"
# define SEARCH "SEARCH"
# define EXIT "EXIT"
# define CONTACT_MAX 8
# define FIELD_MAX 10

# include "../includes/Contact.hpp"

class Phonebook {
public:
	void addContact(int index);

	void getContact(int index);

	void displayContactList(int index);

	Phonebook();

	~Phonebook();

private:
	Contact _contactList[CONTACT_MAX];

	static void trimInfo(const std::string &str);

	static std::string enterInput(const std::string &message);
};

#endif