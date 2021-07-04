// For example, the monuments are named as follows:
// 1  2  3
// 4  5  6
// 7  8  9

// Path followed by traveler: 1->4->7->8->5->2->3->6->9

// You are required to print the path that this traveler follows to visit all places.

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = vector<int>(m);
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int row_start = 0;
    int col_start = 0;
    int row_end = n - 1;
    int col_end = m - 1;
    for (int j = 0; j < arr[0].size(); j++)
    {
        if (j % 2 == 0)
        {
            for (int i = row_start; i <= row_end; i++)
            {
                cout << arr[i][j] << endl;
            }
        }
        else
        {
            for (int i = row_end; i >= row_start; i--)
            {
                cout << arr[i][j] << endl;
            }
        }
    }
    return 0;
}