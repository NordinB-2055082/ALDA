// AUTEURS: Nordin Ben-AL-Lal, Abdullah Yalvac
#include "VirusSourceFinder.h"
using namespace std;

//perform DFS to find reachable nodes within given days
//the time complexity of this function is O(V+E) where V represents the amount of the vertices
//and E the amount of edges.
void VirusSourceFinder::dfs(const Graph& graph, char node, int days, unordered_set<char>& visited) {
    if (days == 0) return;
    visited.insert(node);
    //check if the node exists in the adjacency list
    auto it = graph.adjList.find(node);
    if (it != graph.adjList.end()) {
        for (char neighbor : it->second) {
            if (days <= graph.daysSincePatientZero || !visited.count(neighbor)) { //dont visit the direct neigbours of the infected node we are searching for otherwise problems with performing dfs on the next direct neighbour
                //not sure if this is correct for every solution with more days reach, it shouldnt take direct neighbours of previously visited nodes
                dfs(graph, neighbor, days - 1, visited);
            }
        }
    }
}

//print the reachableMap
//the time complexity of this function is O(V*R), where V is the number of vertices and R the size of the reachable size of out set in DFS
void VirusSourceFinder::printReachableMap(const unordered_map<char, unordered_set<char>>& reachableMap) {
    cout << "Reachable Map:" << endl;
    for (const auto& entry : reachableMap) {
        cout << "Node " << entry.first << ": ";
        for (char reachableNode : entry.second) {
            cout << reachableNode << " ";
        }
        cout << endl;
    }
}

//function to remove nodes with reachable map bigger than nonIsolatedInfectedNodes
//time complexity: O(V) with V the number of vertices in the graph. We are iterating through the map for all nodes, so O(V)
void VirusSourceFinder::removeLargeReachableNodes(unordered_map<char, unordered_set<char>>& reachableMap,
    const unordered_set<char>& nonIsolatedInfectedNodes) {
    vector<char> nodesToRemove;

    for (const auto& entry : reachableMap) {
        if (entry.second.size() > nonIsolatedInfectedNodes.size()) {
            nodesToRemove.push_back(entry.first);
        }
    }

    for (char node : nodesToRemove) {
        reachableMap.erase(node);
    }
}

//function to remove nodes not part of nonIsolatedInfectedNodes
//a O(V*R) time complexity where R is the avg. size of the reachable set.
//V is the number of nodes. 
//iterate through reachable map, remove nodes that are not part of nonIsolatedInfectedNodes
//thus resulting in a O(V*R) time complexity
void VirusSourceFinder::removeNonIsolatedNodes(unordered_map<char, unordered_set<char>>& reachableMap,
    const unordered_set<char>& nonIsolatedInfectedNodes) {
    vector<char> nodesToRemove;

    for (const auto& entry : reachableMap) {
        for (char reachableNode : entry.second) {
            if (!nonIsolatedInfectedNodes.count(reachableNode)) {
                nodesToRemove.push_back(entry.first);
            }
        }
    }

    for (char node : nodesToRemove) {
        reachableMap.erase(node);
    }
}

//compare function for sorting by size of reachable set
//the time complexity is O(1) since lookups in a set is instant(O(1))
bool VirusSourceFinder::compareByReachableSize(const pair<char, unordered_set<char>>& a, const pair<char, unordered_set<char>>& b) {
    return a.second.size() > b.second.size();
}
//time complexity is O(V*log(V)) where V represents the number of vertices in the graph
vector<pair<char, unordered_set<char>>> VirusSourceFinder::sortReachableMapBySize(const unordered_map<char, unordered_set<char>>& reachableMap) {
    // Convert the reachableMap to a vector of pairs
    vector<pair<char, unordered_set<char>>> reachableVector(reachableMap.begin(), reachableMap.end());

    // Sort the vector using the compare function
    sort(reachableVector.begin(), reachableVector.end(), compareByReachableSize);

    return reachableVector;
}


//find the source(s) of the virus
//we have O(V+E) for each time we do a dfs call
//also, for each non-isolated node we have, we do a DFS
//R being the avg. size of a reachable map
//which gives us O(N*(V+E)+ V*R) with N being the number of non-isolated infected nodes,
//V the infected nodes and E the edges or the adjacent list of the non isolated infected nodes
vector<vector<char>> VirusSourceFinder::findSources(const Graph& graph, const unordered_set<char>& infectedNodes, int days) {
    vector<vector<char>> allSources;
    unordered_set<char> isolatedNodes;

    //step 1: Identify isolated infected nodes
    for (char infectedNode : infectedNodes) {
        if (graph.adjList.find(infectedNode) == graph.adjList.end()) {
            isolatedNodes.insert(infectedNode);
            cout << "Geisoleerde node gevonden: " << infectedNode << endl;
        }
    }

    //remove isolated nodes from infected nodes
    unordered_set<char> nonIsolatedInfectedNodes;
    for (char infectedNode : infectedNodes) {
        if (!isolatedNodes.count(infectedNode)) {
            nonIsolatedInfectedNodes.insert(infectedNode);
            cout << "geen geisoleerde node: " << infectedNode << endl;
        }
    }
    //step 2: Store reachable nodes for each non-isolated infected node
    unordered_map<char, unordered_set<char>> reachableMap;
    for (char infectedNode : nonIsolatedInfectedNodes) {
        unordered_set<char> reachableNodes;
        dfs(graph, infectedNode, days, reachableNodes);
        reachableMap[infectedNode] = reachableNodes;
    }
    printReachableMap(reachableMap);

    //step 3: Delete the lists of reachablemaps that are bigger in size than the nonIsolated infected node list
    //this is because they can't be part of the solution because they also reach nodes that are not infected
    removeLargeReachableNodes(reachableMap, nonIsolatedInfectedNodes);
    cout << "Ik heb de te grote verwijderd check het hieronder: " << endl;
    printReachableMap(reachableMap);

    //step 4: Delete lists of reachableMaps that contain non infected nodes
    removeNonIsolatedNodes(reachableMap, nonIsolatedInfectedNodes);
    cout << "Ik heb de onmogelijke oplossingen met niet infected sources ook verwijderd check het hieronder: " << endl;
    printReachableMap(reachableMap);

    //sort reachablemap by size
    //step 5: Find the largest list of reachable nodes
    vector<pair<char, unordered_set<char>>> sortedReachableMap = sortReachableMapBySize(reachableMap);


    // no solution
    if (sortedReachableMap.empty()) {
        //if the size of the infected nodes is as big as the size of the isolated nodes return the isolated nodes otherwise no solution
        if (isolatedNodes.size() == infectedNodes.size()) {

            //step 7: Add isolated nodes to sources list
            vector<char> isolatedSources;
            for (char isolatedNode : isolatedNodes) {
                isolatedSources.push_back(isolatedNode);
            }
            allSources.push_back(isolatedSources);
            return allSources;
        }
        return allSources;
    }


    //if there is a solution with the same size as the infected nodes its always the smallest set because it comes from one infected node
    else if (sortedReachableMap[0].second.size() == nonIsolatedInfectedNodes.size()) {
        //Check if there are sets with the same size because there could be multiple nodes with the same reach
        for (const auto& entry : reachableMap) {
            if (entry.second.size() == sortedReachableMap[0].second.size() && entry.first != *nonIsolatedInfectedNodes.begin()) {
                vector<char> otherSources;
                otherSources.push_back(entry.first);

                for (char isolatedNode : isolatedNodes) {
                    otherSources.push_back(isolatedNode);
                }
                allSources.push_back(otherSources);
            }
        }

        return allSources;
    }

    //elsestatement that searches for solutions of mixed sources
    else {
        int remainingSize = nonIsolatedInfectedNodes.size();
        const auto& lastEntry = *(--reachableMap.end()); // Get the last entry in reachableMap
        char lastElement = lastEntry.first;
        while (remainingSize > 0) {
            for (const auto& entry : sortedReachableMap) {

                //we always take the biggest one and then search for the remaining smaller one if its not there take the biggest that is smaller in size again,
                //at the end if there still is a remaining size and no more solutions to fill it we come in the last else if statement and need to clear all the sources because there is no solution in that case 
                if (entry.second.size() < remainingSize) {
                    if (remainingSize - entry.second.size() > 0) {
                        remainingSize -= entry.second.size();
                        vector<char> mixedSources;
                        mixedSources.push_back(entry.first);
                        for (char isolatedNode : isolatedNodes) {
                            mixedSources.push_back(isolatedNode);
                        }
                        allSources.push_back(mixedSources);
                    }
                }
                else if (entry.second.size() == remainingSize) {
                    vector<char> mixedSources;
                    mixedSources.push_back(entry.first);
                    for (char isolatedNode : isolatedNodes) {
                        mixedSources.push_back(isolatedNode);
                    }
                    allSources.push_back(mixedSources);
                    return allSources; // Found a solution
                }
                else if (entry.first == lastElement) { //at the end of all solutions, no solution
                    allSources.clear();
                    return allSources;
                }
                else {
                    // No solution with the given size

                    break;
                }
            }
        }

    }

    return allSources;
}


