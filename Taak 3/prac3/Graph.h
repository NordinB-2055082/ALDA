// AUTEURS: Nordin Ben-AL-Lal, Abdullah Yalvac
#pragma once
#include <unordered_map>
#include <vector>
using namespace std;

class Graph {
public:
    unordered_map<char, vector<char>> adjList;
    int daysSincePatientZero;

    void addEdge(char u, char v);
};

