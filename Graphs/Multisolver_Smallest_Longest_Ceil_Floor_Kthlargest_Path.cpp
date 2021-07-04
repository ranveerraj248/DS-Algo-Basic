// 1. You are given a graph, a src vertex and a destination vertex.
// 2. You are give a number named "criteria" and a number "k".
// 3. You are required to find and print the values of
// 3.1 Smallest path and it's weight separated by an "@"
// 3.2 Largest path and it's weight separated by an "@"
// 3.3 Just Larger path (than criteria in terms of weight) and it's weight separated by an "@"
// 3.4 Just smaller path (than criteria in terms of weight) and it's weight separated by an "@"
// 3.5 Kth largest path and it's weight separated by an "@"
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
static string spath;
static int spathw = INT_MAX;
static string lpath;
static int lpathw = INT_MIN;
static string cpath;
static int cpathw = INT_MAX;
static string fpath;
static int fpathw = INT_MIN;
static priority_queue<int, vector<pis>, greater<pis>> pq;
void multisolver(vector<vector<Edge *>> graph, int src, int dest, vector<bool> visited, int criteria, int k, string psf, int wsf)
{
    if (src == dest)
    {
        if (wsf < spathw)
        {
            spathw = wsf;
            spath = psf;
        }
        if (wsf > lpathw)
        {
            lpathw = wsf;
            lpath = psf;
        }
        if (wsf > criteria && wsf < cpathw)
        {
            cpathw = wsf;
            cpath = psf;
        }
        if (wsf < criteria && wsf > fpathw)
        {
            fpathw = wsf;
            fpath = psf;
        }
        if (pq.size() < k)
        {
            pq.push(make_pair(wsf, psf));
        }
        else
        {
            if (wsf > pq.top().first)
            {
                pq.pop();
                pq.push(make_pair(wsf, psf));
            }
        }
        return;
    }
    visited[src] = true;
    for (auto edge : graph[src])
    {
        if (visited[edge->nbr] == false)
        {
            multisolver(graph, edge->nbr, dest, visited, criteria, k, psf + to_string(edge->nbr), edge->wt + wsf);
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
    int criteria;
    cin >> criteria;
    int k;
    cin >> k;
    multisolver(graph, src, dest, visited, criteria, k, to_string(src) + "", 0);
    cout << ("Smallest Path = " + spath + "@" + to_string(spathw)) << endl;
    cout << ("Largest Path = " + lpath + "@" + to_string(lpathw)) << endl;
    cout << ("Just Larger Path than " + to_string(criteria) + " = " + cpath + "@" + to_string(cpathw)) << endl;
    cout << ("Just Smaller Path than " + to_string(criteria) + " = " + fpath + "@" + to_string(fpathw)) << endl;
    cout << (to_string(k) + "th largest path = " + pq.top().second + "@" + to_string(pq.top().first)) << endl;
}