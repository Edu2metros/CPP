#include "phonebook.hpp"

std::string truncateString(const std::string& str, int width) {
    if (str.length() > static_cast<std::string::size_type>(width)) {
        return str.substr(0, width - 1) + ".";
    } else {
        return str;
    }
}

bool phoneNumberValid(const std::string& phoneNumber)
{
    if(phoneNumber.empty())
        return false;
    for(std::string::size_type i = 0; i < phoneNumber.size(); i++)
    {
        if(!isdigit(phoneNumber[i]))
            return false;
    }
    return true;
}

void addcontact(Phonebook &phone)
{
    std::string name, last_name, nickname, phoneNumber, darkestSecret;
    std::cout << "Enter first name: ";
    std::getline(std::cin, name);
    if(name.empty())
    {
        std::cout << "First name cannot be empty" << std::endl;
        return;
    }
    std::cout << "Enter Last name: ";
    std::getline(std::cin, last_name);
    if(last_name.empty())
    {
        std::cout << "Last name cannot be empty" << std::endl;
        return;
    }
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    if(nickname.empty())
    {
        std::cout << "Nickname cannot be empty" << std::endl;
        return;
    }
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
    if(darkestSecret.empty())
    {
        std::cout << "Darkest Secret cannot be empty" << std::endl;
        return;
    }
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);    
    if(phoneNumberValid(phoneNumber) == false)
    {
        std::cout << "Phone number is invalid" << std::endl;
        return;
    }
    phone.addContact(name, last_name, nickname, phoneNumber, darkestSecret);
}

int main(void)
{
	std::string line;
    Phonebook phonebook;
    while(true)
    {
		std::cout << "Enter a command: (add, search, exit): ";
		std::getline(std::cin, line);
		if(line == "ADD" || line == "add")
            addcontact(phonebook);
        else if(line == "SEARCH" || line == "search"){
            phonebook.searchContact();
        }
        else if(line == "EXIT" || line == "exit"){
            break;
        }
	}
    return(0);
}