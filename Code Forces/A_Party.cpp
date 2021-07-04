#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
void addEdge(vii &adj, int u, int v)
{
    adj[u].push_back(v);
}
void dfs(int root, int v, vi &maxHeight, vii &adj)
{
    maxHeight[root] = 1;
    int mx = 0;
    for (auto &child : adj[root])
    {
        if (child == v)
            continue;
        else
        {
            dfs(child, root, maxHeight, adj);
            mx = max(mx, maxHeight[child]);
        }
    }
    maxHeight[root] += mx;
}
int main()
{
    int n;
    cin >> n;
    vi maxHeight(n + 1);
    vii adj(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int boss;
        cin >> boss;
        if (boss == -1)
        {
            addEdge(adj, 0, i);
        }
        else
        {
            addEdge(adj, boss, i);
        }
    }
    dfs(0, 0, maxHeight, adj);
    cout << (maxHeight[0] - 1);
    return 0;
}