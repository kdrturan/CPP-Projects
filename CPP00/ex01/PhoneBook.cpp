#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : totalContact(0), currentIndex(0) { }
PhoneBook::~PhoneBook() { }

int strToInt(const std::string& str) {
	if (!str.empty() && str.length() == 1 && str[0] >= '0' && str[0] <= '9')
	{
		return str[0] - '0';
	}
	else
	{
		std::cout << "Invalid input." << std::endl;
	}
	return -1;
}

static bool isOnlyEngChar(const std::string& input) {
	for (size_t i = 0; i < input.length(); ++i) {
		if (!((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))) {
			return false;
		}
	}
	return true;
}

static bool promptNonEmptyLine(const std::string& prompt, std::string& out) {
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, out)) {
            return false;
        }
        if (!out.empty())
		{
			if (!isOnlyEngChar(out))
			{
				std::cout << "Lutfen sadece ingilizce karakterler kullanin.\n";
			}
			else return true;
		}
		else
        	std::cout << "Bu alan bos olamaz. Lutfen tekrar deneyin.\n";
    }
}



void PhoneBook::addContact() {

	Contact contact;
	std::string input;

	if (!promptNonEmptyLine("First name: ", input)) return;
    	contact.setFirstName(input);

	if (!promptNonEmptyLine("Last name: ", input)) return;
    	contact.setLastName(input);

    if (!promptNonEmptyLine("Nickname: ", input)) return;
    	contact.setNickname(input);

    if (!promptNonEmptyLine("Phone number: ", input)) return;
    	contact.setPhoneNumber(input);

    if (!promptNonEmptyLine("Darkest secret: ", input)) return;
    	contact.setDarkestSecret(input);

    if (contact.isValid()) {
        contacts[currentIndex] = contact;
        currentIndex = (currentIndex + 1) % MAX_CONTACTS;
        if (totalContact < MAX_CONTACTS) totalContact++;
        std::cout << "Contact saved.\n";
    } else {
        std::cout << "Contact bilgileri eksik. Kayit yapilmadi.\n";
    }

}

void PhoneBook::displayContacts() const {
	std::cout << std::setw(10) << "Index" << "|"
	          << std::setw(10) << "First Name" << "|"
	          << std::setw(10) << "Last Name" << "|"
	          << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < totalContact; ++i) {
		std::cout << std::setw(10) << i << "|"
		          << std::setw(10) << (contacts[i].getFirstName().length() > 10 ? contacts[i].getFirstName().substr(0, 9) + "." : contacts[i].getFirstName()) << "|"
		          << std::setw(10) << (contacts[i].getLastName().length() > 10 ? contacts[i].getLastName().substr(0, 9) + "." : contacts[i].getLastName()) << "|"
		          << std::setw(10) << (contacts[i].getNickname().length() > 10 ? contacts[i].getNickname().substr(0, 9) + "." : contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::displayContactDetails(int index) const {
	if (index >= 0 && index < totalContact) {
		const Contact& contact = contacts[index];
		std::cout << "First Name: " << contact.getFirstName() << std::endl;
		std::cout << "Last Name: " << contact.getLastName() << std::endl;
		std::cout << "Nickname: " << contact.getNickname() << std::endl;
		std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
	} else {
		std::cout << "Invalid index." << std::endl;
	}
}

void PhoneBook::searchContacts() const {
	if (totalContact == 0) {
		std::cout << "No contacts available." << std::endl;
		return;
	}

	displayContacts();

	std::string input;
	std::cout << "Enter index to view details: ";
	if (!std::getline(std::cin, input)) return;

	try {
		int index = strToInt(input);
		displayContactDetails(index);
	} catch (...) {
		std::cout << "Invalid input.*" << std::endl;
	}
}



