// Given an array Arr of N numbers and another number target, find three integers in the array such that the sum is closest to target. Return the sum of the three integers.

// Example 1:

// Input:
// N = 6, target = 2
// A[] = {-7,9,8,3,1,1}
// Output: 2
// Explanation: There is one triplet with sum
// 2 in the array. Triplet elements are -7,8,
// 1 whose sum is 2.

// Example 2:
// Input:
// N = 4, target = 13
// A[] = {5,2,7,5}
// Output: 14
// Explanation: There is one triplet with sum
// 12 and other with sum 14 in the array.
// Triplet elements are 5, 2, 5 and 2, 7, 5
// respectively. Since abs(13-12) ==
// abs(13-14) maximum triplet sum will be
// preferred i.e 14.
// Your Task:
// Complete threeSumClosest() function and return the expected answer.

// NOTE: If their exists more than one answer then return the maximum sum.

// Expected Time Complexity: O(N*N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 3 ≤ N ≤ 103
// -105 ≤ A[i] ≤ 105
// 1 ≤ target ≤ 105
// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution
{
public:
    int threeSumClosest(vector<int> &arr, int target)
    {

        sort(arr.begin(), arr.end());
        bool flag = 0;

        int ans = arr[0] + arr[1] + arr[2];

        for (int i = 0; i < arr.size() - 2; i++)
        {
            //int final = target-arr[i];

            int l = i + 1;
            int r = arr.size() - 1;

            while (l < r)
            {
                int sum = arr[i] + arr[l] + arr[r];

                if (abs(1ll * target - sum) < abs(1ll * target - ans))
                {
                    ans = sum;
                }
                else if (abs(1ll * target - sum) == abs(1ll * target - ans)) // condition jab difference same hoga similar to example 2
                {
                    if (sum > ans)
                        ans = sum;
                }

                if ((sum) < target)
                {

                    l++;
                }
                else
                {

                    r--;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, target;
        cin >> n >> target;

        vector<int> vec(n);

        for (int i = 0; i < n; ++i)
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

//Position this line where user code will be pasted.
// } Driver Code Ends