#include "FileHandler.h"
#include <fstream>

void FileHandler::readContactsFromFile(const std::string& fileName, AddressBook& addressBook) {
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        // Read contacts from the file and add them to the address book
        std::string line;
        while (std::getline(inputFile, line)) {
            std::string firstName, lastName, address, phoneNumber;
            size_t pos = 0;
            // First name
            pos = line.find(";");
            firstName = line.substr(0, pos);
            line.erase(0, pos + 1);
            // Last name
            pos = line.find(";");
            lastName = line.substr(0, pos);
            line.erase(0, pos + 1);
            // Adress 
            pos = line.find(";");
            address = line.substr(0, pos);
            // phoneNumber
            phoneNumber = line.substr(pos + 1);
            // Create contact object and add to book
            Contact contact = { firstName, lastName, address, phoneNumber };
            addressBook.addContact(firstName + " " + lastName, contact);
        }
        inputFile.close();
    }
    else {
        // Error opening file
        std::cout << "Unable to open the txt file." << std::endl;
        return 1;
    }
}
