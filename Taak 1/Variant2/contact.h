// AUTEURS: Nordin Ben-AL-Lal, Abdullah Yalvac
#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact{
    public:
        //default constructor without parameters
        Contact();
        
        //Params with & because params by value uses copies(= uses memory)
        //If you have a file with 10000 people and all have the same name, it would use a lot of memory
        //  if u needed to get all info about them.
        //--> This is more efficient
        Contact(const std::string &firstName, const std::string &lastName, const std::string &address, const std::string &phoneNumber);
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getAddress() const;
        std::string getPhoneNumber() const;
        std::string getFullName() const;
    private:
        std::string firstName;
        std::string lastName;
        std::string address;
        std::string phoneNumber;
        /*
        Some of the phone numbers are mixed with the letter 'x', 
            so we use strings to represent them.

        */
};
#endif // CONTACT_H