#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "contact.h"

class AddressBook {
public:
    void addContact(const Contact& contact);
    bool deleteContact(const std::string& fullName);
    void queryByFullName(const std::string& fullName) const;
    void queryByLastName(const std::string& lastName) const;
    void printAllContactsSortedByLastName() const;

private:
    std::unordered_map<std::string, Contact> contactsByFullName;
    std::unordered_map<std::string, std::vector<Contact>> contactsByLastName;
};