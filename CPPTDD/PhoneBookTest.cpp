#include <cassert>
#include "PhoneBook.hpp"

void unitTestPhoneBookConstructor() {
	PhoneBook phoneBook("2017");
	assert(phoneBook.year == "2017");
}

void unitTestPhoneBookAddContact() {
	PhoneBook phoneBook("2023");
	phoneBook.addContact("James", "123-456-7890");
	assert(phoneBook.numContacts == 1);
}

void unitTestPhoneBookGetContact() {
	PhoneBook phoneBook("1971");
	phoneBook.addContact("Mike", "777-777-7777");
	assert(phoneBook.getContact("Mike") == "777-777-7777");
}

int main() {
	unitTestPhoneBookConstructor();

	unitTestPhoneBookAddContact();

	unitTestPhoneBookGetContact();

	cout << "The program completed successfully." << endl;

	return 0;
}