// Taak 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// 1. Query by full name
//  hashtable:
//	key = full name because we can assume every full name is unique (see 2.2)
//	value = contact info
//  This is the fastest way to do it
// 2. Delete by full name:
//	use the same way to look up the contact and simply delete it 

#include <iostream>
#include "AddressBook.h"
#include "FileHandler.h"

int main() {
    AddressBook addressBook;

    // Read contacts from file
    // This is O(N) 
    FileHandler::readContactsFromFile("../data.txt", addressBook);

    //Test example: add contact 
    //Contact newContact("Nordin", "Ben-Al-Lal", "123 Sint-Truiden", "1234DatZieJeVanHier");
    //addressBook.addContact(newContact);
    
    // Query the contact info of the person you want for example lisa sosa out the dataset
    addressBook.queryContact("Lisa Blackburn");
    std::cout << "Delete Lisa Blackburn:" << std::endl;
    // Test example: delete contact
    addressBook.deleteContact("Lisa Blackburn");
    std::cout << "Zoek Lisa Blackburn na deleten:" << std::endl;
    addressBook.queryContact("Lisa Blackburn");

    return 0;
}