// AUTEURS: Nordin Ben-AL-Lal, Abdullah Yalvac
#pragma once

#include "Contact.h"
#include <unordered_map>

class AddressBook {
public:
    void addContact(const Contact& contact);
    void queryContact(const std::string& fullName) const;
    void deleteContact(const std::string& fullName);


private:
    std::unordered_map<std::string, Contact> contacts;
};