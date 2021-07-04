// 1. You are given a number n1, representing the number of rows of 1st matrix.
// 2. You are given a number m1, representing the number of columns of 1st matrix.
// 3. You are given n1*m1 numbers, representing elements of 2d array a1.
// 4. You are given a number n2, representing the number of rows of 2nd matrix.
// 5. You are given a number m2, representing the number of columns of 2nd matrix.
// 6. You are given n2*m2 numbers, representing elements of 2d array a2.
// 7. If the two arrays representing two matrices of dimensions n1 * m1 and n2 * m2 can be multiplied, display the contents of prd array as specified in output Format.
// 8. If the two arrays can't be multiplied, print "Invalid input".

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n1, m1;
    cin >> n1;
    cin >> m1;
    int arr1[n1][m1];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            cin >> arr1[i][j];
        }
    }

    int n2, m2;
    cin >> n2;
    cin >> m2;
    int arr2[n2][m2];
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cin >> arr2[i][j];
        }
    }
    int res[n1][m2];
    int i, j, k;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < n2; k++)
                res[i][j] += arr1[i][k] * arr2[k][j];
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}