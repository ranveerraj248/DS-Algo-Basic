// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to return the count of the number of elements in
    //the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m)
    {
        vector<int> dp(1e5 + 1);
        fill(dp.begin(), dp.end(), -1);
        int count = 0;
        int i = 0;
        int j = 0;
        sort(a, a + n);
        sort(b, b + m);
        while (i < n && j < m)
        {
            if (a[i] == b[j])
            {
                if (dp[a[i]] == -1)
                {
                    count++;
                    dp[a[i]] = 1;
                }
                i++;
                j++;
            }
            else if (a[i] < b[j])
            {
                i++;
            }
            else if (b[j] < a[i])
            {
                j++;
            }
        }

        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
} // } Driver Code Ends