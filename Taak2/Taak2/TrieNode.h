// AUTEURS: Nordin Ben-AL-Lal, Abdullah Yalvac
#pragma once
#include <vector>

const char END_CHAR = '#';

class TrieNode {
public:
    TrieNode* children[256];
    std::vector<int> productIndices;

    TrieNode();

    ~TrieNode();

    TrieNode(const TrieNode&) = delete;

    TrieNode& operator=(const TrieNode&) = delete;
};