#include <iostream>
#include <map>

using namespace std;

class PhoneBook {
public:
	string year;
	int numContacts;
	PhoneBook(string year);
	void addContact(string name, string number);
	string getContact(string name);
private:
	map<string, string> contacts;
};