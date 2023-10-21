#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>

void Filehandler::readContactsFromFile(const std::string& fileName, addressbook& addressbook) {
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        // Read contacts from the file and add them to the address book
        std::string line;
        while (std::getline(inputFile, line)) {
            std::string firstName, lastName, address, phoneNumber;
            std::istringstream lineStream(line);

            if (std::getline(lineStream, firstName, ';') &&
                std::getline(lineStream, lastName, ';') &&
                std::getline(lineStream, address, ';') &&
                std::getline(lineStream, phoneNumber)) {

                Contact contact = { firstName, lastName, address, phoneNumber };
                addressbook.addContact(contact);
            }
        }
        inputFile.close();
    }
    else {
        // Error opening file
        std::cout << "Unable to open the txt file." << std::endl;
        return;
    }
}