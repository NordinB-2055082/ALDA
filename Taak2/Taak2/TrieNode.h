// AUTEURS: Nordin Ben-AL-Lal, Abdullah Yalvac
#pragma once
#include <vector>
#include <unordered_map>
#include <string>

const char END_CHAR = '#';

//allemaal in comment gezet
/*
class TrieNode {
public:

    std::unordered_map<unsigned char, TrieNode*> children;
    std::vector<int> productIndices;

    TrieNode();

    ~TrieNode();

    TrieNode(const TrieNode&) = delete;

    TrieNode& operator=(const TrieNode&) = delete;
};
*/

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    std::vector<int> productIndices;
};
