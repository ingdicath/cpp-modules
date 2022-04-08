//
// Created by Diana catherine Salamanca leguizamon on 2/1/22.
//

#include "../includes/Phonebook.hpp"

Phonebook::Phonebook() {
}

Phonebook::~Phonebook() {
}

std::string Phonebook::enterInput(const std::string &message) {
	std::string contactField;
	while (true) {
		std::cout << message;
		std::getline(std::cin, contactField);
		if (std::cin.eof()) {
			std::cin.clear();
			exit(EXIT_SUCCESS);
		}
		if (contactField.empty())
			std::cout << RED << "Contact can’t have empty fields." << RESET << std::endl;
		else
			return contactField;
	}
}

void Phonebook::addContact(int index) {
	Contact contact;
	std::string userInput;

	contact.setIndexContact(index);
	userInput = enterInput("First Name: ");
	contact.setFirstName(userInput);
	userInput = enterInput("Last Name: ");
	contact.setLastName(userInput);
	userInput = enterInput("Nickname: ");
	contact.setNickName(userInput);
	userInput = enterInput("Phone number: ");
	contact.setPhoneNumber(userInput);
	userInput = enterInput("Darkest secret: ");
	contact.setDarkestSecret(userInput);
	this->_contactList[index] = contact;
	std::cout << GREEN << "Contact added successfully!!\n" << RESET << std::endl;
}

void Phonebook::trimInfo(const std::string &str) {
	if (str.length() <= FIELD_MAX)
		std::cout << std::setw(FIELD_MAX) << std::right << str;
	else
		std::cout << std::setw(FIELD_MAX - 1)
				  << std::right << str.substr(0, 9) << ".";
}

/**
 * Display a contact list's overview, when SEARCH is typed.
 */
void Phonebook::displayContactList(int index) {
	if (this->_contactList[index].getIndexContact() == -1)
		return;

	std::cout << std::setw(FIELD_MAX) << std::right
			  << this->_contactList[index].getIndexContact() << "|";
	trimInfo(this->_contactList[index].getFirstName());
	std::cout << "|";
	trimInfo(this->_contactList[index].getLastName());
	std::cout << "|";
	trimInfo(this->_contactList[index].getNickName());
	std::cout << std::endl;
}

/**
 * Display contact's information, when user choose an index from contact list's overview.
 */
void Phonebook::getContact(int index) {
	if (this->_contactList[index].getIndexContact() == -1) {
		std::cout << ORANGE << "Contact doesn't exist." << std::endl;
		std::cout << "Please choose an index from the contact list.\n"
				  << RESET << std::endl;
		return;
	}
	std::cout << "First Name: " << this->_contactList[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->_contactList[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_contactList[index].getNickName() << std::endl;
	std::cout << "Phone number: " << this->_contactList[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->_contactList[index].getDarkestSecret()
			  << std::endl << std::endl;
}
