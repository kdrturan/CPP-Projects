#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#define MAX_CONTACTS 8

class PhoneBook {
private:
	Contact contacts[MAX_CONTACTS];
	int totalContact;
	int currentIndex;

public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContacts() const;
	void displayContacts() const;
	void displayContactDetails(int index) const;
    const Contact& getContact(int idx) const;
	int getTotalContacts() const;
};


#endif