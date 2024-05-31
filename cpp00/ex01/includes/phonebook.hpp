#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include "contact.hpp"

std::string truncateString(const std::string &str);

class Phonebook
{
private:
	Contact contacts[8];
	int size;
	int index;

public:
	Phonebook() : size(0), index(0) {}
	void addContact(const std::string &name, const std::string &last_name, const std::string &nickname,
					const std::string &phoneNumber, const std::string &darkestSecret);
	void searchContact(void) const;
};

#endif