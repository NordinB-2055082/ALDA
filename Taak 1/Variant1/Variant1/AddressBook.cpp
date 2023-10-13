#include "AddressBook.h"
#include <iostream>


// The average time complexity for adding a contact into an unordered map is O(1) on average
// This is because the data structure uses a hash table to store the data 
void AddressBook::addContact(const Contact& contact) {
    contacts[contact.getFullName()] = contact;
}


// The time complexity for searching for a specific contact in an unordered map is O(1) on average
// Similar to insertion, this is because the hash table allows for constant-time lookups
// Because we had to assume the names were unique, we will not have any collisions
void AddressBook::queryContact(const std::string& fullName) const {
    auto it = contacts.find(fullName);
    if (it != contacts.end()) {
        Contact contact = it->second;
        // Show contact information
        std::cout << "First Name: " << contact.getFirstName() << std::endl;
        std::cout << "Last Name: " << contact.getLastName() << std::endl;
        std::cout << "Address: " << contact.getAddress() << std::endl;
        std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
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