// AUTEURS: Nordin Ben-AL-Lal, Abdullah Yalvac
#pragma once

#include "contact.h"
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

class AddressBook {
private:
    std::multimap<std::string, Contact> contacts; // using multimap to store contacts by last name

public:
    void loadFromFile(const std::string& filename);
    void addContact(const Contact& newContact);
    void deleteContact(const std::string& fullName);
    void queryContactByFullName(const std::string& fullName) const;
    void queryContactsByLastName(const std::string& lastName) const;
    void outputAddressBook() const;
};
