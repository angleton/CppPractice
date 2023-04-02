#include "PhoneBook.hpp"

PhoneBook::PhoneBook(string year) {
	this->year = year;
	this->numContacts = 0;
}

void PhoneBook::addContact(string name, string number) {
	this->numContacts += 1;
	this->contacts[name] = number;
}

string PhoneBook::getContact(string name) {
	return this->contacts[name];
}