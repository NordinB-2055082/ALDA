#include <iostream>
#include "addressbook.h"
#include "filehandler.h"

int main(){
    addressbook addressbook;
    Filehandler::readContactsFromFile("./data.txt", addressbook);
    //Making an example as test
    //We'll add a new contact 
    Contact newContact("Abdullah", "Yalvac", "456 Heusden-Zolder", "5678 DitHadJeNietVerwacht");
    addressbook.addContact(newContact);
    
    //Query all the info about a contact
    //By firstname
    addressbook.queryContact("Abdullah");
    std::cout << "----------------------------------------------" << std::endl;
    //By lastname
    addressbook.queryContact("Yalvac");    
    std::cout << "----------------------------------------------" << std::endl;
    //by phoneNumber
    addressbook.queryContact("5678 DitHadJeNietVerwacht");    
    std::cout << "----------------------------------------------" << std::endl;
    //By address
    addressbook.queryContact("456 Heusden-Zolder");    
    std::cout << "----------------------------------------------" << std::endl;
    //Now we delete a contact
    addressbook.deleteContact("Abdullah Yalvac");
    //Checking if it actually is deleted
    addressbook.queryContact("456 Heusden-Zolder");
    std::cout << "----------------------------------------------" << std::endl;
    //We can also do it on other people from the data.txt file(this one is nr12 from data.txt)
    addressbook.queryContact("689 Jason Path Suite 912, Lake Joshuabury, OH 91686");

    return 0;
}