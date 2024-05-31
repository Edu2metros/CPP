#include "includes/contact.hpp"
#include "includes/phonebook.hpp"

void Phonebook::addContact(const std::string &name, const std::string &last_name, const std::string &nickname,
					const std::string &phoneNumber, const std::string &darkestSecret)
{
	contacts[index].setName(name);
	contacts[index].setLastName(last_name);
	contacts[index].setNickname(nickname);
	contacts[index].setPhoneNumber(phoneNumber);
	contacts[index].setDarkestSecret(darkestSecret);
	index = (index + 1) % 8;
	if (size < 8)
		size++;
}

void Phonebook::searchContact(void) const
{
	if (size == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}
	std::cout << std::right << std::setw(10) << "Index" << " | "
				<< std::setw(10) << "First Name" << " | "
				<< std::setw(10) << "Last Name" << " | "
				<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << std::right << std::setw(10) << i + 1 << " | "
					<< std::setw(10) << truncateString(contacts[i].getName()) << " | "
					<< std::setw(10) << truncateString(contacts[i].getLastName()) << " | "
					<< std::setw(10) << truncateString(contacts[i].getNickname()) << std::endl;
	}
	int index;
	std::cout << "Enter the index of the contact you want to display: ";
	std::cin >> index;

	if (std::cin.fail() || index < 1 || index > size)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index. Please enter a valid index." << std::endl;
	}
	else
	{
		std::cout << "First Name: " << contacts[index - 1].getName() << std::endl;
		std::cout << "Last Name: " << contacts[index - 1].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index - 1].getNickname() << std::endl;
		std::cout << "Phone Number: " << contacts[index - 1].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index - 1].getDarkestSecret() << std::endl;
	}
}