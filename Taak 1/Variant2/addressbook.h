// AUTEURS: Nordin Ben-AL-Lal, Abdullah Yalvac
#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include "contact.h"
#include <unordered_map>

class addressbook{
    public:        
        void addContact(const Contact &contact);
        void deleteContact(const std::string &fullName);
        void queryContact(const std::string &anyParameter) const;
    private:
        std::unordered_map<std::string, Contact> contacts;
};
#endif // ADDRESSBOOK_H