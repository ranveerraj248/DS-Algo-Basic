#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vii;
void changeState(vs &ans, int i, int j)
{
    if (ans[i][j] == '0')
    {
        ans[i][j] = '1';
    }
    else
    {
        ans[i][j] = '0';
    }
}
void toggle(vs &ans, int i, int j)
{
    changeState(ans, i, j);
    if (j - 1 >= 0)
    {
        changeState(ans, i, j - 1);
    }
    if (i - 1 >= 0)
    {
        changeState(ans, i - 1, j);
    }
    if (j + 1 < ans[0].size())
    {
        changeState(ans, i, j + 1);
    }
    if (i + 1 < ans.size())
    {
        changeState(ans, i + 1, j);
    }
}
int main()
{
    vector<vector<int>> grid(3, (vector<int>(3)));
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cin >> grid[i][j];
        }
    }
    vs ans(3, "111");
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] % 2 == 1)
            {
                toggle(ans, i, j);
            }
        }
    }
    for (auto str : ans)
    {
        cout << str << endl;
    }
    return 0;
}