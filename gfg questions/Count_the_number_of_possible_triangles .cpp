// Given an unsorted array arr[] of n positive integers.
// Find the number of triangles that can be formed with three different array elements as lengths of three sides of triangles.
// { Driver Code Starts
//Initial Template for C

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr, arr + n);
        int triangles = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int k = i + 2;
            for (int j = i + 1; j < n; j++)
            {
                while (k < n && arr[i] + arr[j] > arr[k])
                {
                    ++k;
                }
                triangles += k - j - 1;
            }
        }
        return triangles;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.findNumberOfTriangles(arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends