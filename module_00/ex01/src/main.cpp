//
// Created by Diana catherine Salamanca leguizamon on 2/1/22.
//

#include "../includes/Phonebook.hpp"

static void print_main_header() {
	std::cout << CYAN << std::setfill('*') << std::setw(43) << "*" << std::endl;
	std::cout << "      Welcome to my awesome PhoneBook      " << std::endl;
	std::cout << std::setfill('*') << std::setw(43) << "*" << RESET << std::endl;
	std::cout << std::setfill(' ') << std::endl;
}

static void print_menu() {
	std::cout << "- To add a contact, please type: "
			  << YELLOW << "ADD" << RESET << std::endl;
	std::cout << "- To search a contact, please type: "
			  << YELLOW << "SEARCH" << RESET << std::endl;
	std::cout << "- To exit, please type: "
			  << YELLOW << "EXIT" << RESET << std::endl;
}

static void print_search_header() {
	std::cout << std::setw(28) << "Contact list" << std::endl;
	std::cout << PURPLE << std::setfill('-') << std::setw(43) << "-" << std::endl;
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	std::cout << std::setfill('-') << std::setw(43) << "-";
	std::cout << std::setfill(' ') << std::endl;
}

int searchContactByIndex() {
	std::string arg;
	while (true) {
		std::cout << CYAN << "Please select an index to display information: "
				  << RESET << std::endl;
		std::getline(std::cin, arg);
		if (std::cin.eof()) {
			std::cin.clear();
			exit(EXIT_SUCCESS);
		} else if (arg.size() > 1 || arg[0] < '0' || arg[0] > '7') {
			std::cout << RED << "Not a valid argument, try again" << RESET << std::endl;
		} else {
			break;
		}
	}
	return (arg[0] - '0');
}

void search(Phonebook &phonebook, int index) {
	if (index == 0) {
		std::cout << ORANGE << "Contact list is empty. Let's begin to add a new contact!!.\n"
				  << RESET << std::endl;
	} else {
		print_search_header();
		for (int i = 0; i < CONTACT_MAX; i++)
			phonebook.displayContactList(i);
		int indexToSearch = searchContactByIndex();
		phonebook.getContact(indexToSearch);
	}
}

int main() {
	Phonebook phonebook;
	std::string command;
	int index = 0;

	print_main_header();
	while (true) {
		print_menu();
		std::getline(std::cin, command);
		if (std::cin.eof()) {
			std::cin.clear();
			exit(EXIT_SUCCESS);
		}
		if (command == EXIT) {
			std::cout << CYAN << "Thanks for using this Phonebook!!!" << RESET << std::endl;
			break;
		} else if (command == ADD) {
			if (index == CONTACT_MAX) {
				index = 0;
				std::cout << ORANGE << "Contact list is full, but you can overwrite contacts."
						  << RESET << std::endl;
			}
			phonebook.addContact(index);
			index++;
		} else if (command == SEARCH) {
			search(phonebook, index);
		} else
			std::cout << RED << "Wrong input or command must be in Capital letters.\n"
					  << RESET << std::endl;
	}
	return 0;
}
