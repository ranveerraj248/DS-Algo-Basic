// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers (1's and 0's), representing elements of 2d array a.
// 4. Consider this array a maze and a player enters from top-left corner in east direction.
// 5. The player moves in the same direction as long as he meets '0'. On seeing a 1, he takes a 90 deg right turn.
// 6. You are required to print the indices in (row, col) format of the point from where you exit the matrix.

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

    int direction = 0;
    int i = 0;
    int j = 0;
    // 0 == east
    // 1 == south
    // 2 == west
    // 3 == north

    while (true)
    {
        direction = (direction + arr[i][j]) % 4;

        if (direction == 0)
        {
            j++;
        }
        else if (direction == 1)
        {
            i++;
        }
        else if (direction == 2)
        {
            j--;
        }
        else if (direction == 3)
        {
            i--;
        }

        if (i < 0)
        {
            i++;
            break;
        }
        if (j < 0)
        {
            j++;
            break;
        }
        if (i == arr.size())
        {
            i--;
            break;
        }
        if (j == arr[0].size())
        {
            j--;
            break;
        }
    }
    cout << i << endl;
    cout << j << endl;
    return 0;
}