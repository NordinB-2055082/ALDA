// Taak 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Read data from the text file and populate the address book
    std::ifstream inputFile("../data.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
			std::cout << "KAK";
        }
        inputFile.close();
    }
    else {
        std::cout << "Unable to open the txt file." << std::endl;
        return 1;
    }
}


