// Taak 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// 1. Query by full name
//  hashtable:
//	key = full name because we can assume every full name is unique (see 2.2)
//	value = contact info
//
// 2. Delete by full name:
//	gebruik dezelfde opzoekmanier om daarna te verwijderen 
/*
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Read data from the text file and populate the address book
    std::ifstream inputFile("../data.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
			std::cout << "KAK";
        }
        inputFile.close();
    }
    else {
        std::cout << "Unable to open the txt file." << std::endl;
        return 1;
    }
}
*/

#include <iostream>
#include "AddressBook.h"
#include "FileHandler.h"

int main() {
    AddressBook addressBook;

    // Read contacts from a file
    FileHandler::readContactsFromFile("../data.txt", addressBook);

    // Example: Add a new contact 
    Contact newContact("John", "Doe", "123 Main St", "555-123-4567");
    addressBook.addContact(newContact);

    // Example: Query a contact by full name
    addressBook.queryContact("John Doe");

    // Example: Delete a contact
    addressBook.deleteContact("John Doe");

    return 0;
}


