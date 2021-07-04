// 1. You are given a graph, a source vertex and a destination vertex.
// 2. You are required to find and print all paths between source and destination. Print
//      them in lexicographical order.

//     E.g. Check the following paths
//              012546
//              01256
//              032546
//              03256

//     The lexicographically smaller path is printed first.
#include <iostream>
#include <vector>
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
void printAllPaths(vector<vector<Edge *>> graph, int src, int dest, vector<bool> visited, string psf)
{
    if (src == dest)
    {
        cout << psf << endl;
        return;
    }
    visited[src] = true;
    for (auto edge : graph[src])
    {
        if (visited[edge->nbr] == false)
        {
            printAllPaths(graph, edge->nbr, dest, visited, psf + to_string(edge->nbr));
        }
    }
    visited[src] = false;
}
int main()
{

    int vtces;
    cin >> vtces;
    cin.ignore();
    vector<vector<Edge *>> graph(vtces);
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
    printAllPaths(graph, src, dest, visited, to_string(src) + "");
}