#include "Contact.h"

#include "contact.h"
#include <iostream>

Contact::Contact() : firstName(""), lastName(""), address(""), phoneNumber("") {} // Default constructor, otherwise error

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& address, const std::string& phoneNumber)
    : firstName(firstName), lastName(lastName), address(address), phoneNumber(phoneNumber) {}

std::string Contact::getFullName() const {
    return firstName + " " + lastName;
}

std::string Contact::getLastName() const {
    return lastName;
}

void Contact::print() const {
    std::cout << "Name: " << getFullName() << "\n";
    std::cout << "Address: " << address << "\n";
    std::cout << "Phone: " << phoneNumber << "\n";
}