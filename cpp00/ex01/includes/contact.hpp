#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string name;
    std::string last_name;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    Contact() {}

    std::string getName() const;
    void setName(const std::string &name);
    std::string getLastName() const;
    void setLastName(const std::string &lastName);
    std::string getNickname() const;
    void setNickname(std::string nickname);
    std::string getPhoneNumber() const;
    void setPhoneNumber(std::string number);
    std::string getDarkestSecret() const;
    void setDarkestSecret(std::string dark);
};

#endif