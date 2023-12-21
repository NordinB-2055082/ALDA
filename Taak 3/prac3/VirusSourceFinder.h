// AUTEURS: Nordin Ben-AL-Lal, Abdullah Yalvac
#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>

#include "Graph.h"
using namespace std;

class VirusSourceFinder
{
public:
    static vector<vector<char>> findSources(const Graph& graph, const std::unordered_set<char>& infectedNodes, int days);

private:
    static void dfs(const Graph& graph, char node, int days, unordered_set<char>& visited);
    static void printReachableMap(const unordered_map<char, unordered_set<char>>& reachableMap);
    static void removeLargeReachableNodes(unordered_map<char, unordered_set<char>>& reachableMap, const unordered_set<char>& nonIsolatedInfectedNodes);
    static void removeNonIsolatedNodes(unordered_map<char, unordered_set<char>>& reachableMap, const unordered_set<char>& nonIsolatedInfectedNodes);
    static bool compareByReachableSize(const pair<char, unordered_set<char>>& a, const pair<char, unordered_set<char>>& b);
    static vector<pair<char, unordered_set<char>>> sortReachableMapBySize(const unordered_map<char, unordered_set<char>>& reachableMap);
};
