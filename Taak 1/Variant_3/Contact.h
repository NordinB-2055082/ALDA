#pragma once
#include <string>

class Contact {
public:
    Contact(); //default constructor, otherwise error
    Contact(const std::string& firstName, const std::string& lastName, const std::string& address, const std::string& phoneNumber);
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getAddress() const;
    const std::string& getPhoneNumber() const;

private:
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string phoneNumber;
};