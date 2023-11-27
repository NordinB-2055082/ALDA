#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include "Trie.h"

class ProductReader {
public:
    ProductReader(const std::string& filename);
    void loadProductsIntoTrie(Trie& trie);

private:
    std::string filename;
};
