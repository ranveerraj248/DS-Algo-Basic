#include <bits/stdc++.h>
using namespace std;
// bool canPlace(int i, int j, vector<vector<int>> &ans, int h, int w)
// {
//     if ((((i - 1) >= 0) && (ans[i - 1][j] == 1)) || (((j - 1) >= 0) && (ans[i][j - 1] == 1)) || ((i + 1) <= h - 1) && (ans[i + 1][j] == 1) || ((j + 1 <= w - 1) && (ans[i][j + 1] == 1)) || ((i - 1 >= 0) && (j - 1 >= 0) && (ans[i - 1][j - 1] == 1)) || ((i - 1 >= 0) && (j + 1 <= w - 1) && (ans[i - 1][j + 1] == 1)) || ((i + 1 <= j) && (j - 1 >= 0) && (ans[i + 1][j - 1] == 1)) || ((i + 1 <= h - 1) && (j + 1 <= w - 1) && (ans[i + 1][j + 1] == 1)))
//         return false;
//     return true;
// }
// void helpher(int curRow, int curCol, vector<vector<int>> &ans, int h, int w)
// {
//     for (int i = 0; i < h; i++)
//     {
//         for (int j = 0; j < w; j++)
//         {
//             if ((i == 0) || (i == h - 1) || (j == 0) || (j == w - 1))
//             {
//                 if (canPlace(i, j, ans, h, w))
//                 {
//                     ans[i][j] = 1;
//                 }
//             }
//         }
//     }
//     for (int i = 0; i < h; i++)
//     {
//         for (int j = 0; j < w; j++)
//         {
//             cout << ans[i][j];
//         }
//         cout << endl;
//     }
// }
void solve()
{
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
    {
        if (i == 1 || i == h)
        {
            for (int j = 1; j <= w; j++)
            {
                if (j % 2 == 0)
                {
                    cout << "0";
                }
                else
                {
                    cout << "1";
                }
            }
            cout << endl;
        }
        else
        {
            if (i % 2 == 1 && i != h - 1)
            {
                for (int j = 1; j <= w; j++)
                {
                    if (j == 1 || j == w)
                    {
                        cout << "1";
                    }
                    else
                    {
                        cout << "0";
                    }
                }
                cout << endl;
            }
            else
            {
                for (int i = 1; i <= w; i++)
                {
                    cout << "0";
                }
                cout << endl;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}