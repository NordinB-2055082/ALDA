#pragma once
#include "Product.h"
#include "TrieNode.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Product.h"
#include "TrieNode.h"


enum TrieType {
    ID,
    TITLE
};

// AUTEURS: Nordin Ben-AL-Lal, Abdullah Yalvac
class ProductSearch {
public:
    ProductSearch();

    ~ProductSearch();

    void loadProducts(const std::string& filename);

    void insertProductToTrie(const Product& product, int index, TrieType type);

    std::vector<int> searchProducts(const std::string& query, TrieType type);

    void printProducts(const std::vector<int>& indices, int start, int end);

    void searchAndPrint(const std::string& query);


private:
    std::vector<Product> products;
    TrieNode* idTrieRoot;
    TrieNode* titleTrieRoot;
    std::vector<std::string> split(const std::string& s, char delimiter);
    std::string removeQuotes(const std::string& s);
};