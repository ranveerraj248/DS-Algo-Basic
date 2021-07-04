// 1. You are given a graph, a src vertex and a destination vertex.
// 2. You are required to find if a path exists between src and dest. If it does, print true
//      otherwise print false.

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Edge
{
public:
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

static bool hasPath(vector<Edge *> graph[], int src, int dest, vector<bool> visited)
{
    if (src == dest)
    {
        return true;
    }
    visited[src] = true;
    for (auto edge : graph[src])
    {
        if (visited[edge->nbr] == false)
        {
            bool hasNbrPath = hasPath(graph, edge->nbr, dest, visited);
            if (hasNbrPath == true)
            {
                return true;
            }
        }
    }

    return false;
}
int main()
{

    int vtces;
    cin >> vtces;
    cin.ignore();
    vector<Edge *> graph[vtces];
    vector<bool> visited(vtces, false);
    int edges;
    cin >> edges;
    cin.ignore();
    for (int i = 0; i < edges; i++)
    {
        stringstream ss;
        string s;
        getline(cin, s);
        ss << s;
        string val;
        ss >> val;
        int v1 = stoi(val);
        ss >> val;
        int v2 = stoi(val);
        ss >> val;
        int wt = stoi(val);
        graph[v1].push_back(new Edge(v1, v2, wt));
        graph[v2].push_back(new Edge(v2, v1, wt));
    }
    int src;
    cin >> src;
    int dest;
    cin >> dest;

    bool path = hasPath(graph, src, dest, visited);

    if (path)
    {
        cout << true;
    }
    else
    {
        cout << "false";
    }
    return 0;
}