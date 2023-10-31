#include "Contact.h"

#include "contact.h"
#include <iostream>

Contact::Contact() : firstName(""), lastName(""), address(""), phoneNumber("") {} // Default constructor, otherwise error

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& address, const std::string& phoneNumber)
    : firstName(firstName), lastName(lastName), address(address), phoneNumber(phoneNumber) {}

const std::string& Contact::getFirstName() const {
    return firstName;
}

const std::string& Contact::getLastName() const {
    return lastName;
}

const std::string& Contact::getAddress() const {
    return address;
}

const std::string& Contact::getPhoneNumber() const {
    return phoneNumber;
}