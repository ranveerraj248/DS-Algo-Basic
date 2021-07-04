// C++ program to print all paths
// from a source to destination.
#include <bits/stdc++.h>
#include <list>
using namespace std;
vector<vector<int>> allPaths;
// A directed graph using
// adjacency list representation
class Graph
{
    int V;          // No. of vertices in graph
    list<int> *adj; // Pointer to an array containing adjacency lists

    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int, int, bool[], int[], int &);

public:
    Graph(int V); // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add v to u’s list.
}

// Prints all paths from 's' to 'd'
void Graph::printAllPaths(int s, int d)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];

    // Create an array to store paths
    int *path = new int[V];
    int path_index = 0; // Initialize path[] as empty

    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index);
}

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int &path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    // If current vertex is same as destination, then print
    // current path[]
    if (u == d)
    {
        // for (int i = 0; i < path_index; i++)
        //     cout << path[i] << " ";
        // cout << endl;
        vector<int> temp;
        for (int i = 0; i < path_index; i++)
        {
            temp.push_back(path[i]);
        }
        allPaths.push_back(temp);
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index);
    }

    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}

// Driver program
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    int s = 1, d = 5;
    //cout << "Following are all different paths from " << s << " to " << d << endl;
    g.printAllPaths(s, d);
    // cout << endl;
    // cout << allPaths.size() << " " << allPaths[0][0] << " " << allPaths[1].size() << endl;
    set<int, greater<int>> pathSize;
    for (auto &array : allPaths)
    {
        for (auto &element : array)
        {
            cout << element << " ";
        }
        cout << endl;
        pathSize.insert(array.size() - 1);
    }
    // //sort(pathSize.begin(), pathSize.end());
    // set<int, greater<int>>::iterator itr;
    // itr = pathSize.begin();
    // itr++;
    // cout << *itr;
    // //cout << "Largest Element is :" << pathSize(1);
    // //cout << "Second Largest Element is :" <<
    return 0;
}
