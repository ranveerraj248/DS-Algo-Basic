// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are required to find the span of input. Span is defined as difference of maximum value and minimum value.

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int spanOfArray(vector<int> arr)
{
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    return max - min;
}
int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int digit;
        cin >> digit;
        arr.push_back(digit);
    }
    cout << spanOfArray(arr);
}