#include "addressbook.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

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
    std::cout << "Query Tracey Payne by full name" << std::endl;
    addressBook.queryByFullName("Tracey Payne");
    std::cout << "Query the last name Zuniga" << std::endl;
    addressBook.queryByLastName("Zuniga");
    std::cout << "Delete Pam Zuniga" << std::endl;
    //delete contact
    addressBook.deleteContact("Pam Zuniga");
    std::cout << "Query Pam Zuniga to see if she is gone" << std::endl;
    addressBook.queryByFullName("Pam Zuniga");

    //command to sort and print the contacts
    addressBook.printAllContactsSortedByLastName();

    return 0;
}