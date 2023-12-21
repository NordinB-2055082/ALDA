// AUTEURS: Nordin Ben-AL-Lal, Abdullah Yalvac
#include "Graph.h"

void Graph::addEdge(char u, char v) {
    adjList[u].push_back(v);
}