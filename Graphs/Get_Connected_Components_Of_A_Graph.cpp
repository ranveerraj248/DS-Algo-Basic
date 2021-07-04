// 1. You are given a graph.
// 2. You are required to find and print all connected components of the graph.
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> pis;
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
string drawTreeAndGenerateComp(vector<vector<Edge *>> graph, int src, string comp, vector<bool> visited)
{
    visited[src] = true;
    //comp += to_string(src);
    for (auto e : graph[src])
    {
        if (visited[e->nbr] == false)
        {
            comp += drawTreeAndGenerateComp(graph, e->nbr, comp, visited);
        }
    }
    string ans = to_string(src) + comp;
    return ans;
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
    vector<string> comps;
    static string comp;
    for (int i = 0; i < vtces; i++)
    {
        if (visited[i] == false)
        {
            comp = "";
            comp = drawTreeAndGenerateComp(graph, i, comp, visited);
            comps.push_back(comp);
        }
    }

    for (string path : comps)
    {
        cout << path << endl;
    }
}