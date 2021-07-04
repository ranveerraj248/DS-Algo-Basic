#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
void dfs(int point, int n, vi &visited, vii &arr)
{
    visited[point] = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i][0] == arr[point][0] || arr[i][1] == arr[point][1]) && visited[i] == -1)
        {
            dfs(i, n, visited, arr);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vii arr(n, (vi(2)));
    vi visited(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == -1)
        {
            dfs(i, n, visited, arr);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}