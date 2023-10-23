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
    //example usage of addressBook methods:

    //query contact
    addressBook.queryByFullName("Tracey Payne");
    addressBook.queryByLastName("Zuniga");
    //delete contact
    addressBook.deleteContact("Pam Zuniga");
    //command to sort and print the contacts
    addressBook.printAllContactsSortedByLastName();

    return 0;
}