// You are given a n*m matrix where n are the number of rows and m are the number of columns. You are also given n*m numbers representing the elements of the matrix.
// // You will be given a ring number 's' representing the ring of the matrix.
// You will be given a number 'r' representing number of rotations in an anti-clockwise manner of the specified ring.
// You are required to rotate the 's'th ring by 'r' rotations and display the rotated matrix.

#include <iostream>
using namespace std;
void rotateShell(int arr[][], int n, int m, int s, int r)
{
}
int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int shell;
    cin >> shell;
    int rotations;
    cin >> rotations;
    rotateShell(arr, n, m, s, r);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}