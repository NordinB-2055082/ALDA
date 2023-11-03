// AUTEURS: Nordin Ben-AL-Lal, Abdullah Yalvac
#include "addressbook.h"


int main() {
    //added loadFromFile for cleaner code 
    AddressBook addressBook;
    addressBook.loadFromFile("../data.txt");

    //example usage of addressBook methods:

    //query contact
    std::cout << "Query Tracey Payne by full name" << std::endl;
    // query by full name
    addressBook.queryContactByFullName("Tracey Payne");

    std::cout << "Query the last name Zuniga" << std::endl;
    addressBook.queryContactsByLastName("Zuniga");
    std::cout << "Delete Pam Zuniga" << std::endl;
    //delete contact
    addressBook.deleteContact("Pam Zuniga");
    std::cout << "Query Pam Zuniga to see if she is gone" << std::endl;
    addressBook.queryContactByFullName("Pam Zuniga");

    // print the entire address book sorted by last name
    std::cout << "Address Book (Sorted by Last Name):\n";
    addressBook.outputAddressBook();


    return 0;
}