// 1. You are given a graph.
// 2. You are required to find and print if the graph is connected (there is a path from
//      every vertex to every other).

#include <bits/stdc++.h>
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
void isConnected(vector<vector<Edge *>> graph, int src, vector<bool> visited)
{

    visited[src] = true;
    for (auto v : graph[src])
    {
        if (visited[v->nbr] == false)
        {
            isConnected(graph, v->nbr, visited);
        }
    }
    return;
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
    int src = graph[0][0]->src;
    isConnected(graph, src, visited);
    for (bool flag : visited)
    {
        if (!flag)
        {
            cout << "false";
            return 0;
        }
    }
    cout << "true";
    return 0;
}