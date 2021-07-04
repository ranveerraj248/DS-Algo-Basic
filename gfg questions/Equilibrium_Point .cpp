// { Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n)
    {

        int i = 0;
        int low = 0;
        int high = n - 1;
        long long leftSum = 0;
        long long rightSum = 0;
        for (i = 0; i < n; i++)
        {
            if (low == high && leftSum == rightSum)
            {
                return low + 1;
            }
            if (low == high)
            {
                return -1;
            }
            if (leftSum > rightSum)
            {
                rightSum += a[high];
                high--;
            }
            else if (rightSum > leftSum)
            {
                leftSum += a[low];
                low++;
            }
            else
            {
                rightSum += a[high];
                high--;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main()
{

    long long t;

    //taking testcases
    cin >> t;

    while (t--)
    {
        long long n;

        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends