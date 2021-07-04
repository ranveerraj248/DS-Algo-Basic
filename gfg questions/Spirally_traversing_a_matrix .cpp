// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        int row_start = 0;
        int col_start = 0;
        int row_end = r - 1;
        int col_end = c - 1;
        int totalElemnts = r * c;
        int curElement = 0;
        vector<int> result;
        while (curElement < totalElemnts)
        {
            //
            //  ---- > going left to right
            //
            for (int i = col_start; i <= col_end && curElement < totalElemnts; i++)
            {
                result.push_back(matrix[row_start][i]);
                curElement++;
            }
            row_start++;
            //   |
            //   | going down
            //  \ /
            for (int i = row_start; i <= row_end && curElement < totalElemnts; i++)
            {
                result.push_back(matrix[i][col_end]);
                curElement++;
            }
            col_end--;
            //
            //  <--- going right to left
            //
            for (int i = col_end; i >= col_start && curElement < totalElemnts; i--)
            {
                result.push_back(matrix[row_end][i]);
                curElement++;
            }
            row_end--;
            //  ^
            //  | going up
            //  |
            for (int i = row_end; i >= row_start && curElement < totalElemnts; i--)
            {
                result.push_back(matrix[i][col_start]);
                curElement++;
            }
            col_start++;
        }
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends