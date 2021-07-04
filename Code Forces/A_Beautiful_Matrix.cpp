#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> mat(5, (vector<int>(5)));
    int curX, curY;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 1)
            {
                curX = i + 1;
                curY = j + 1;
            }
        }
    }
    int result = abs(3 - curX) + abs(3 - curY);
    cout << result << endl;
    return 0;
}