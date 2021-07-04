// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {

        vector<long long int> productArray(n);
        long long int product = 1;
        int countZeros = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                countZeros++;
            }
            else
            {

                product *= nums[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (countZeros == 0)
            {
                productArray[i] = product / nums[i];
            }
            else if (countZeros == 1)
            {
                if (nums[i] == 0)
                {
                    productArray[i] = product;
                }
                else
                {
                    productArray[i] = 0;
                }
            }
            else
            {
                productArray[i] = 0;
            }
        }
        return productArray;
    }
};

// { Driver Code Starts.
int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--)
    {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr, n); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends