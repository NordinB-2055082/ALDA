#include "addressbook.h"

// ADDING a contact using a multimap is O(Log N)
// DELETING is O(N *log N), it involves searchiung for the contact O(N) and then deleting the contact which is logarithmic with a multimap
// QUERY contact by last name is O(log N + M), once the last name is found (Log N), the number of contacts with that last name is 'M', and outputting these contacts would take O(M) time.
// PRINT OUTPUT of the entire addressBook is now O(N) because it is already sorted because of the multimap


// EXPLANATION WHY MULTIMAP VS MAP VS WHAT WE DID FIRST
// 
// If each last name should correspond to only one contact, and there are no duplicates, 
// a std::map might be more efficient in terms of memory and potentially quicker lookups since it avoids storing duplicate keys.
// but in our case there are duplicates so we use a multimap
//
// What we did now is way more efficient in terms of memory and time, because we didnt have to worry about a sorting algorithm like we did in our previous version using radix sort
// the insertion of a multimap is quite efficient already and is in our opinion better suited for this scenario
// 
// So we can conclude that even that the insertion and lookup functions are slower using a multimap, our project is OVERALL way better and faster
//
void AddressBook::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string firstName, lastName, address, phoneNumber;
            std::getline(ss, firstName, ';');
            std::getline(ss, lastName, ';');
            std::getline(ss, address, ';');
            std::getline(ss, phoneNumber, ';');
            Contact newContact(firstName, lastName, address, phoneNumber);
            addContact(newContact);
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void AddressBook::addContact(const Contact& newContact) {
    contacts.insert(std::make_pair(newContact.getLastName(), newContact));
}

void AddressBook::deleteContact(const std::string& fullName) {
    auto it = std::find_if(contacts.begin(), contacts.end(), [&](const std::pair<std::string, Contact>& element) {
        return (element.second.getFirstName() + " " + element.second.getLastName()) == fullName;
        });
    if (it != contacts.end()) {
        contacts.erase(it);
    }
    else {
        std::cerr << "Contact " << fullName << " not found in the address book." << std::endl;
    }
}

void AddressBook::queryContactByFullName(const std::string& fullName) const {
    auto it = std::find_if(contacts.begin(), contacts.end(), [&](const std::pair<std::string, Contact>& element) {
        return (element.second.getFirstName() + " " + element.second.getLastName()) == fullName;
        });
    if (it != contacts.end()) {
        std::cout << "Contact found: " << it->second.getFirstName() << " " << it->second.getLastName()
            << " Address: " << it->second.getAddress() << " Phone: " << it->second.getPhoneNumber() << std::endl;
    }
    else {
        std::cerr << "Contact " << fullName << " not found in the address book." << std::endl;
    }
}

void AddressBook::queryContactsByLastName(const std::string& lastName) const {
    auto range = contacts.equal_range(lastName);
    if (range.first != contacts.end()) {
        std::cout << "Contacts with last name " << lastName << ":\n";
        for (auto it = range.first; it != range.second; ++it) {
            std::cout << it->second.getFirstName() << " " << it->second.getLastName()
                << " Address: " << it->second.getAddress() << " Phone: " << it->second.getPhoneNumber() << std::endl;
        }
    }
    else {
        std::cerr << "No contacts found with last name " << lastName << " in the address book." << std::endl;
    }
}

void AddressBook::outputAddressBook() const {
    for (const auto& entry : contacts) {
        std::cout << entry.second.getFirstName() << " " << entry.second.getLastName()
            << " Address: " << entry.second.getAddress() << " Phone: " << entry.second.getPhoneNumber() << std::endl;
    }
}
