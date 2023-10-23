#include "addressbook.h"
#include <fstream>
#include <sstream>
#include <string>

int main() {
    AddressBook addressBook;
    std::ifstream dataFile("../data.txt");
    std::string line;

    while (std::getline(dataFile, line)) {
        std::istringstream iss(line);
        std::string firstName, lastName, address, phoneNumber;
        if (std::getline(iss, firstName, ';') && std::getline(iss, lastName, ';') && std::getline(iss, address, ';') && std::getline(iss, phoneNumber)) {
            Contact contact(firstName, lastName, address, phoneNumber);
            addressBook.addContact(contact);
        }
    }
    // Example usage of addressBook methods:
    addressBook.queryByFullName("Tracey Payne");
    //addressBook.deleteContact("Pam Zuniga");
    addressBook.queryByLastName("Zuniga");
    //addressBook.printAllContactsSortedByLastName();

    return 0;
}