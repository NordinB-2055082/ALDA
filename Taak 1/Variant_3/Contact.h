#pragma once
#include <string>

class Contact {
public:
    Contact(); //default constructor, otherwise error
    Contact(const std::string& firstName, const std::string& lastName, const std::string& address, const std::string& phoneNumber);
    std::string getFullName() const;
    std::string getLastName() const;
    void print() const;

private:
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string phoneNumber;
};