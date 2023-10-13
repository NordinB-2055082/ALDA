#include "AddressBook.h"

void AddressBook::addContact(const Contact& contact) {
    contacts[contact.getFullName()] = contact;
}

void AddressBook::queryContact(const std::string& fullName) const {
    auto it = contacts.find(fullName);
    if (it != contacts.end()) {
        Contact contact = it->second;
        // Output contact information
    }
    else {
        // Contact not found
        std::cout << "Can't find the contact";
    }
}

void AddressBook::deleteContact(const std::string& fullName) {
    auto it = contacts.find(fullName);
    if (it != contacts.end()) {
        contacts.erase(it);
    }
    else {
        // Contact not found
        std::cout << "Can't delete, contact doesn't exist";
    }
}
