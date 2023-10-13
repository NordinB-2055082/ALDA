#include "Variant_1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>


// 1. Query by full name
//  hashtable:
//	key = volledige naam 
//	value = contact object
//
// 2. Delete by full name:
//	gebruik dezelfde opzoekmanier om daarna te verwijderen 

/*
// Define a Contact structure
struct Contact {
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string phoneNumber; // string omdat er ook "x" "()" voorkomen
};