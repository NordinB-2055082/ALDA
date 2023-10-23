#include "addressbook.h"
#include <iostream>
#include <algorithm>
#include <vector>

void AddressBook::addContact(const Contact& contact) {
    std::string fullName = contact.getFullName();
    std::string lastName = contact.getLastName();
    contactsByFullName[fullName] = contact;
    contactsByLastName[lastName].push_back(contact);
}

bool AddressBook::deleteContact(const std::string& fullName) {
    auto it = contactsByFullName.find(fullName);
    if (it != contactsByFullName.end()) {
        std::string lastName = it->second.getLastName();
        auto& contactsWithSameLastName = contactsByLastName[lastName];
        auto removeIt = std::remove_if(contactsWithSameLastName.begin(), contactsWithSameLastName.end(), [&fullName](const Contact& c) {
            return c.getFullName() == fullName;
            });
        if (removeIt != contactsWithSameLastName.end()) {
            contactsWithSameLastName.erase(removeIt);
        }
        contactsByFullName.erase(it);
        return true;
    }
    return false;
}

void AddressBook::queryByFullName(const std::string& fullName) const {
    auto it = contactsByFullName.find(fullName);
    if (it != contactsByFullName.end()) {
        it->second.print();
    }
    else {
        std::cout << "Contact not found." << std::endl;
    }
}

void AddressBook::queryByLastName(const std::string& lastName) const {
    auto it = contactsByLastName.find(lastName);
    if (it != contactsByLastName.end()) {
        for (const Contact& contact : it->second) {
            contact.print();
        }
    }
    else {
        std::cout << "No contacts with the last name: " << lastName << std::endl;
    }
}

//Radix sorting algorithm is O(k*n) where k is the lenght of the last name of the contact 
void AddressBook::printAllContactsSortedByLastName() const {
    
    std::vector<Contact> allContacts;
    for (const auto& entry : contactsByLastName) {
        allContacts.insert(allContacts.end(), entry.second.begin(), entry.second.end());
    }

    //Maximum length of last names
    size_t maxLastNameLength = 0;
    for (const Contact& contact : allContacts) {
        maxLastNameLength = std::max(maxLastNameLength, contact.getLastName().length());
    }

    //Radix Sort on last names https://www.geeksforgeeks.org/radix-sort/; https://www.cs.helsinki.fi/u/tpkarkka/opetus/13s/spa/lecture03.pdf
    for (int i = maxLastNameLength - 1; i >= 0; i--) {
        std::vector<Contact> sortedContacts(allContacts.size());
        int counting[256] = { 0 }; // Ascii

        //occurrences of characters at position i
        for (const Contact& contact : allContacts) {
            unsigned char lastNameChar = (i < contact.getLastName().length()) ? contact.getLastName()[i] : 0;
            counting[lastNameChar]++;
        }

        //cumulative counts
        for (int j = 1; j < 256; j++) {
            counting[j] += counting[j - 1];
        }

        //build the sorted array based on counts
        for (int j = allContacts.size() - 1; j >= 0; j--) {
            const Contact& contact = allContacts[j];
            unsigned char lastNameChar = (i < contact.getLastName().length()) ? contact.getLastName()[i] : 0;
            sortedContacts[counting[lastNameChar] - 1] = contact;
            counting[lastNameChar]--;
        }

        //copy sorted array back to allContacts
        allContacts.assign(sortedContacts.begin(), sortedContacts.end());
    }

    //print
    for (const Contact& contact : allContacts) {
        contact.print();
    }
}
/* //n log n can be improved
void AddressBook::printAllContactsSortedByLastName() const {
    // Create a vector to hold the contacts sorted by last name
    std::vector<Contact> sortedContacts;

    // Iterate through the contactsByLastName unordered_map
    for (const auto& entry : contactsByLastName) {
        for (const Contact& contact : entry.second) {
            sortedContacts.push_back(contact);
        }
    }

    // Sort the contacts by last name
    std::sort(sortedContacts.begin(), sortedContacts.end(), [](const Contact& a, const Contact& b) {
        return a.getLastName() < b.getLastName();
        });

    // Print the sorted contacts
    for (const Contact& contact : sortedContacts) {
        contact.print();
    }
}
*/