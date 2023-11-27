// main.cpp
#include "ProductSearch.h"

#include <iostream>

int main() {
    ProductSearch productSearch;
    productSearch.loadProducts("../testcsv.csv");

    std::cout << "Enter search string for suggestions. Press enter to get the full list or q to quit." << std::endl;

    std::string input;
    std::getline(std::cin, input);

    while (input != "q") {
        productSearch.searchAndPrint(input);

        std::cout << "Enter search string for suggestions. Press enter to get the full list or q to quit." << std::endl;
        std::getline(std::cin, input);
    }

    return 0;
}