#include "addressbook.h"
#include <iostream>
/*
We add a new contact to our unordered map named contacts. 
The time complexity here is O(1). If the data wasn't unique,
so we had multiple "John Doe" in our txt file, we could get a
hash collision. Since we have unique data, this becomes O(1).
*/
void addressbook::addContact(const Contact &contact){
    contacts.insert({contact.getFullName(), contact});        
}

/*
Deleting a contact works the same was as adding a contact. 
By using a hash table(and having no collisions, unique data), we can look up instantly data
So, the combination of those makes this O(1).
*/
void addressbook::deleteContact(const std::string &fullName){
    auto contact = contacts.find(fullName);
    if(contact != contacts.end()){
        contacts.erase(contact);
        std::cout << "Contact has been deleted succesfully." << std::endl;
    }
    else{
        std::cout << "Please enter an existing contact, this one does not exist." << std::endl;
    }
}
/*
This one is O(N), we are iterating over all the elements in contacts
If we could use a fullName as a key, like in variant1, it would be O(N) since fullNames are unique.   
*/
void addressbook::queryContact(const std::string &anyParameter) const{
    bool found = false;
    for(const auto &entry:contacts){
        const Contact &contact = entry.second;
        if(contact.getFirstName() == anyParameter || contact.getLastName() == anyParameter || contact.getAddress() == anyParameter || contact.getPhoneNumber() == anyParameter){
            found = true;
            std::cout << "Contact found!" << std::endl;
            std::cout << "Name: " << contact.getFullName() << std::endl;
            std::cout << "Address: " << contact.getAddress() << std::endl;
            std::cout << "Phone number:" << contact.getPhoneNumber() <<std::endl;
        }
    }            
    if(!found){
        std::cout << "Can't find the contact!" <<std::endl;
    }
}