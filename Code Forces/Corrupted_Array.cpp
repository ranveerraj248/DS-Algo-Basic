// You are given a number n and an array b1,b2,…,bn+2, obtained according to the following algorithm:

// some array a1,a2,…,an was guessed;
// array a was written to array b, i.e. bi=ai (1≤i≤n);
// The (n+1)-th element of the array b is the sum of the numbers in the array a, i.e. bn+1=a1+a2+…+an;
// The (n+2)-th element of the array b was written some number x (1≤x≤109), i.e. bn+2=x; The
// array b was shuffled.
// For example, the array b=[2,3,7,12,2] it could be obtained in the following ways:

// a=[2,2,3] and x=12;
// a=[3,2,7] and x=2.
// For the given array b, find any array a that could have been guessed initially.

// Input
// The first line contains a single integer t (1≤t≤104). Then t test cases follow.

// The first line of each test case contains a single integer n (1≤n≤2⋅105).

// The second row of each test case contains n+2 integers b1,b2,…,bn+2 (1≤bi≤109).

// It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output:

// "-1", if the array b could not be obtained from any array a;
// n integers a1,a2,…,an, otherwise.
// If there are several arrays of a, you can output any.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n + 2];
        for (int i = 0; i < n + 2; i++)
        {
            cin >> arr[i];
        }

        int largest, second;
        if (arr[0] < arr[1])
        {
            largest = arr[1];
            second = arr[0];
        }
        else
        {
            largest = arr[0];
            second = arr[1];
        }
        for (int i = 2; i < n + 2; i++)
        {
            if (arr[i] > largest)
            {
                second = largest;
                largest = arr[i];
            }

            else if (arr[i] > second && arr[i] != largest)
            {
                second = arr[i];
            }
        }
        int sum = 0;
        vector<int> ans;
        for (int i = 0; i < n + 2; i++)
        {
            if (arr[i] != largest && arr[i] != second)
            {
                sum += arr[i];
                ans.push_back(arr[i]);
            }
        }
        if (sum == largest || sum == second)
        {
            for (auto element : ans)
            {
                cout << element << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }
}