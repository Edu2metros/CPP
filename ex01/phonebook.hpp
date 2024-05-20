#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

std::string truncateString(const std::string& str, int width);

class Contact {
public:
    std::string name;
    std::string last_name;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    Contact() {}

    Contact(const std::string& name, const std::string& last_name, const std::string& nickname, 
            const std::string& phoneNumber, const std::string& darkestSecret)
        : name(name), last_name(last_name), nickname(nickname), phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}
};

class Phonebook {
private:
    Contact contacts[2];
    int size;
    int index;

public:
	Phonebook() : size(0), index(0) {}
    void addContact(const std::string& name, const std::string& last_name, const std::string& nickname,
                    const std::string& phoneNumber, const std::string& darkestSecret) {
        contacts[index] = Contact(name, last_name, nickname, phoneNumber, darkestSecret);
        index = (index + 1) % 8;
        if (size < 8)
            size++;
    }

void searchContact() const {
    if (size == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    std::cout << std::right << std::setw(10) << "Index" << " | "
              << std::setw(10) << "First Name" << " | "
              << std::setw(10) << "Last Name" << " | "
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << std::right << std::setw(10) << i + 1 << " | "
                  << std::setw(10) << truncateString(contacts[i].name, 10) << " | "
                  << std::setw(10) << truncateString(contacts[i].last_name, 10) << " | "
                  << std::setw(10) << truncateString(contacts[i].nickname, 10) << std::endl;
    }
    int index;
    std::cout << "Enter the index of the contact you want to display: ";
    std::cin >> index;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (index >= 1 && index <= size) {
        std::cout << "First Name: " << contacts[index - 1].name << std::endl;
        std::cout << "Last Name: " << contacts[index - 1].last_name << std::endl;
        std::cout << "Nickname: " << contacts[index - 1].nickname << std::endl;
        std::cout << "Phone Number: " << contacts[index - 1].phoneNumber << std::endl;
        std::cout << "Darkest Secret: " << contacts[index - 1].darkestSecret << std::endl;
    } else {
        std::cout << "Invalid index. Please enter a valid index." << std::endl;
    }
}
};
