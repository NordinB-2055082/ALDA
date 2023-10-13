#include "Contact.h"

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& address, const std::string& phoneNumber)
    : firstName(firstName), lastName(lastName), address(address), phoneNumber(phoneNumber) {
}

std::string Contact::getFullName() const {
    return firstName + " " + lastName;
}
