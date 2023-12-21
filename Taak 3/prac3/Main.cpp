// AUTEURS: Nordin Ben-AL-Lal, Abdullah Yalvac
/*ANALYSE:
There are 2 or maybe 3 solutions that we think are the most suitable.
Starting with using a Graph & a DFS approach. It is a bit faster than BFS(see later) and it also does not take that much space(for our cases),
    what makes it suitable for us. It could be a problem for big graphs where you actually do use a certain amount of space since we're dealing with recursion.
If we have to recall the dfs-function a lot of times, it could result in a stack overflow.

We can also use a 2D-matrix for our problem. It can be expanded really easily if needed so it would be great if the set of data is growing fast.
Downside of this would be that you have to have a matrix which is V*V times big with V being the amount of edges in the graph. So it also takes quite some memory

Dynamic programming is possible too: we would again have a base case and use recursion but by using memoization,
    we would not have to calculate already calculated results again.
This clearly increases the efficiency of the program since we use less space than before.
Downside of this would be while handling large sets of data, you would need a lot of space to store some results.

Time-complexity of BFS: O(V+E+V*days),
Time-complexity of DFS: O(V+E)
    where V is the amount of vertices in the graph,
    E the amount of edges
    and days in BFS being the amount of days that have passed already.

Advantages:
-Efficiency: DFS is more efficient than the BFS-approach as explained above
-Space complexity: For small/mediumsized graphs, it is quite low as we use recursion
    without using additional data structures that would take more space
Disadvantages:
-Usage of memory: it can cause problems when used for large graphs since you have to use recursion
    it can cause a stack overflow as said above.

Since the data we have to handle is not that big, worries about recursion would not be needed actually.
Time complexity of the functions are in comment below.

All of this resulting in us choosing a DFS-approach for this problem.
*/

#include <iostream>
#include <unordered_set>

#include "Graph.h"
#include "VirusSourceFinder.h"
using namespace std;
int main()
{
    Graph graph;
    graph.addEdge('A', 'B');
    graph.addEdge('A', 'C');

    graph.addEdge('B', 'A');
    graph.addEdge('B', 'D');

    graph.addEdge('C', 'A');
    graph.addEdge('C', 'D');
    graph.addEdge('C', 'E');

    graph.addEdge('D', 'B');
    graph.addEdge('D', 'C');
    graph.addEdge('D', 'E');
    graph.addEdge('D', 'F');

    graph.addEdge('E', 'C');
    graph.addEdge('E', 'D');
    graph.addEdge('E', 'G');

    graph.addEdge('F', 'D');
    graph.addEdge('F', 'G');
    graph.addEdge('F', 'H');

    graph.addEdge('G', 'E');
    graph.addEdge('G', 'F');
    graph.addEdge('G', 'H');

    graph.addEdge('H', 'F');
    graph.addEdge('H', 'G');
    graph.addEdge('H', 'I');

    graph.addEdge('I', 'H');
    graph.addEdge('I', 'J');

    graph.addEdge('J', 'I');
    unordered_set<char> infectedNodes = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'K' };
    int days = 2;

    graph.daysSincePatientZero = days + 1;
    vector<vector<char>> allSources = VirusSourceFinder::findSources(graph, infectedNodes, days + 1);

    cout << "Possible sources of the virus:" << endl;

    for (const auto& sources : allSources) {
        if (!sources.empty()) {
            // Print sources
            for (char source : sources) {
                cout << source << " ";
            }
        }
        cout << endl;
    }

    return 0;
}