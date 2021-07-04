#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
vii adjList;
void dfs(int idx, vi &visited)
{

    visited[idx] = 1;
    for (int &v : adjList[idx])
    {
        if (visited[v] == -1)
        {
            dfs(v, visited);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vi visited(m + 1);
    adjList.resize(m + 1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        int temp = -1;
        ans = k == 0 ? ans + 1 : ans;
        for (int j = 0; j < k; j++)
        {
            int u;
            cin >> u;
            if (j == 0)
            {
                temp = u;
            }
            visited[u] = -1;
            if (j > 0)
            {
                adjList[temp].push_back(u);
                adjList[u].push_back(temp);
            }
        }
    }
    int count = 0;
    for (int i = 1; i < visited.size(); i++)
    {
        if (visited[i] == -1)
        {
            count++;
            dfs(i, visited);
        }
    }
    ans += count > 0 ? count - 1 : 0;
    cout << ans << endl;
    return 0;
}