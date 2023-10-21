#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "addressbook.h"

class Filehandler {
public:
    static void readContactsFromFile(const std::string& fileName, addressbook& addressbook);
};
#endif // FILEHANDLER_H