// 1. You are given an array(arr) of distinct integers and a target.
// 2. You have to print all the pairs having their sum equal to the target.

#include <iostream>
#include <algorithm>
using namespace std;

void targetSumPair(int arr[], int n, int target)
{
    sort(arr, arr + n);
    int li = 0;
    int ri = n - 1;
    while (li < ri)
    {
        if (arr[li] + arr[ri] > target)
        {
            ri--;
        }
        else if (arr[li] + arr[ri] < target)
        {
            li++;
        }
        else
        {
            cout << arr[li] << ", " << arr[ri] << endl;
            li++;
            ri--;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    targetSumPair(arr, n, target);
    return 0;
}