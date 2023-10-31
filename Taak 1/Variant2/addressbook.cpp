#include "addressbook.h"
#include <iostream>
/*
We add a new contact to our unordered map named contacts. 
The time complexity here is O(1). If the data wasn't unique,
so we had multiple "Thomas Jansens" in our txt file, we could get a
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
AnyParameter could be a lastName, firstName, address or phoneNumber.
FirstNames/LastNames are NOT unique, bv there could be multiple people with
a LastName like Payne, so this makes it O(N).
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

/*
FEEDBACK:
Alternatives: 
You could use a vector to put all contacts in an addressbook. 
However, this would be a bit slower due to the fact we're dealing with a lot of data. 
An array can be used too, but there is a downside to it. We have to go through the entire array
    to find all contacts that have the name Peter for example. This would be O(n)
    If we delete a contact given the fullName, we would have to shift all the others one place to the left, what also is o(n).
    In an unordered map is it O(n) given a fullName(is unique).
Using a list would give us the same time complexity as a vector(O(N)), 
    so no need to use it as well since it gives us the same downside as when we use a vector.
*/
