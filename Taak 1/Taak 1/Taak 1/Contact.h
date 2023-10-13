#pragma once
#include <string>

class Contact {
public:
    Contact(const std::string& firstName, const std::string& lastName, const std::string& address, const std::string& phoneNumber);
    std::string getFullName() const;
   
private:
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string phoneNumber; // We use a string because the numbers can contain x, ( or )
};

