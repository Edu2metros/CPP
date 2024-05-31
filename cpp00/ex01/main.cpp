#include "includes/contact.hpp"
#include "includes/phonebook.hpp"

std::string truncateString(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

bool	phoneNumberValid(const std::string &phoneNumber)
{
	if (phoneNumber.empty())
		return (false);
	for (std::string::size_type i = 0; i < phoneNumber.size(); i++)
	{
		if (!isdigit(phoneNumber[i]))
			return (false);
	}
	return (true);
}

void	addcontact(Phonebook &phone)
{
	std::string name, last_name, nickname, phoneNumber, darkestSecret;
	std::cout << "Enter first name: ";
	std::getline(std::cin, name);
	if (name.empty())
	{
		std::cout << "First name cannot be empty" << std::endl;
		return ;
	}
	std::cout << "Enter Last name: ";
	std::getline(std::cin, last_name);
	if (last_name.empty())
	{
		std::cout << "Last name cannot be empty" << std::endl;
		return ;
	}
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	if (nickname.empty())
	{
		std::cout << "Nickname cannot be empty" << std::endl;
		return ;
	}
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, darkestSecret);
	if (darkestSecret.empty())
	{
		std::cout << "Darkest Secret cannot be empty" << std::endl;
		return ;
	}
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phoneNumber);
	if (phoneNumberValid(phoneNumber) == false)
	{
		std::cout << "Phone number is invalid" << std::endl;
		return ;
	}
	phone.addContact(name, last_name, nickname, phoneNumber, darkestSecret);
}

std::string to_lower(std::string line)
{
	for (std::string::size_type i = 0; i < line.size(); i++)
	{
		if (line[i] >= 'A' && line[i] <= 'Z')
			line[i] += 32;
	}
	return (line);
}

int	main(void)
{
	std::string line;
	Phonebook phonebook;
	while (true)
	{
		std::cout << "Enter a command: (add, search, exit): ";
		std::getline(std::cin, line);
		line = to_lower(line);
		if (line == "add")
			addcontact(phonebook);
		else if (line == "search")
			phonebook.searchContact();
		else if (line == "exit")
			break ;
	}
	return (0);
}