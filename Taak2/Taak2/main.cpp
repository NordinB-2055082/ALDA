// AUTEURS: Nordin Ben-AL-Lal, Abdullah Yalvac
#include "ProductSearch.h"

#include <iostream>

int main() {
    ProductSearch productSearch;
    productSearch.loadProducts("../testcsv.csv");

    std::cout << "Enter search string for suggestions and you have to end with #. Press enter to get the full list or q to quit." << std::endl;

    std::string input;
    std::getline(std::cin, input);

    while (!input.empty() && input != "q" && input.back() == END_CHAR) {
        productSearch.searchAndPrint(input);
        std::cout << "Enter search string for suggestions and you have to end with #. Press enter to get the full list or q to quit." << std::endl;
        std::getline(std::cin, input);
    }

    return 0;
}