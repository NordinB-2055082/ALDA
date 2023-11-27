#include "TrieNode.h"
#include <algorithm>

TrieNode::TrieNode() {
    std::fill(children, children + 256, nullptr);
}

TrieNode::~TrieNode() {
    for (auto child : children) {
        delete child;
    }
}