//
// Created by Diana catherine Salamanca leguizamon on 2/1/22.
//

#include "../includes/Contact.hpp"

Contact::Contact() {
	this->_idContact = -1;
}

Contact::~Contact() {
}

/**
 * Getters
 */
int Contact::getIndexContact() const {
	return this->_idContact;
}

std::string Contact::getFirstName() {
	return this->_firstName;
}

std::string Contact::getLastName() {
	return this->_lastName;
}

std::string Contact::getNickName() {
	return this->_nickname;
}

std::string Contact::getPhoneNumber() {
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() {
	return this->_darkestSecret;
}

/**
 * Setters
 */
void Contact::setIndexContact(int index) {
	this->_idContact = index;
}

void Contact::setFirstName(const std::string &firstName) {
	this->_firstName = firstName;
}

void Contact::setLastName(const std::string &lastName) {
	this->_lastName = lastName;
}

void Contact::setNickName(const std::string &nickName) {
	this->_nickname = nickName;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkSecret) {
	this->_darkestSecret = darkSecret;
}
