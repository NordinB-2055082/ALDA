#include "contact.h"

Contact::Contact():firstName(""), lastName(""), address(""), phoneNumber("") {}

Contact::Contact(const std::string &firstName,const std::string &lastName,const std::string &address,const std::string &phoneNumber):firstName(firstName), lastName(lastName), address(address), phoneNumber(phoneNumber){
}

std::string Contact::getFirstName() const{
    return firstName;
}
std::string Contact::getLastName() const{
    return lastName;
}

std::string Contact::getFullName() const{
    return firstName + " " + lastName;
}
std::string Contact::getAddress() const{
    return address;
}
std::string Contact::getPhoneNumber() const{
    return phoneNumber;
}