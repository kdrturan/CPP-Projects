// ...existing code...
#include "PhoneBook.hpp"
#include "Contact.hpp"

#include <iostream>
#include <string>

int main()
{
    PhoneBook phonebook;
    std::string cmd;

    std::cout << "KOMUTLAR: ADD, SEARCH, EXIT" << std::endl;
    while (true)
    {
        std::cout << "> ";
        if (!std::getline(std::cin, cmd))
            break;

        if (cmd == "ADD")
        {
            phonebook.addContact();      
        }
        else if (cmd == "SEARCH")
        {
            phonebook.searchContacts();  
        }
        else if (cmd == "EXIT")
        {
            break;
        }
        else if (cmd.empty())
        {
            continue;
        }
        else
        {
            std::cout << "Invalid input. Select one of them: ADD, SEARCH, EXIT" << std::endl;
        }
    }

    std::cout << "Program sonlandırıldı." << std::endl;
    return 0;
}
