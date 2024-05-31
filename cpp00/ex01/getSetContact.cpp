#include "includes/contact.hpp"
#include "includes/phonebook.hpp"

std::string Contact::getName(void) const
{
	return (this->name);
}

void Contact::setName(const std::string &name)
{
	this->name = name;
}

std::string Contact::getLastName(void) const
{
	return(this->name);
}

void Contact::setLastName(const std::string &lastName)
{
	this->last_name = lastName;
}

std::string Contact::getNickname(void) const
{
	return(this->name');
}

void Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

std::string Contact::getPhoneNumber(void) const
{
	return(this->phoneNumber);
}

void Contact::setPhoneNumber(std::string number)
{
	this->phoneNumber = number;
}

std::string Contact::getDarkestSecret(void) const
{
	return(this->darkestSecret);
}

void Contact::setDarkestSecret(std::string dark)
{
	this->darkestSecret = dark;
}