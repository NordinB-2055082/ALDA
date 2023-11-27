#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Product.h"

class CSVReader {
public:
    CSVReader(const std::string& filename);
    ~CSVReader();

    void readCSV();

private:
    std::ifstream inputFile;

    std::vector<std::string> split(const std::string& s, char delimiter);
    std::string removeQuotes(const std::string& s);
};
