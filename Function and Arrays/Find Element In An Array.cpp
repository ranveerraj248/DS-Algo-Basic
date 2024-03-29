// 1.You are given a number n, representing the size of array a.
// 2.You are given n distinct numbers, representing elements of array a.
// 3. You are given another number d.
// 4. You are required to check if d number exists in the array a and at what index (0 based). If found print the index, otherwise print -1.

#include <iostream>
#include <vector>
using namespace std;

int elementInArray(vector<int> arr, int d)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == d)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    vector<int> arr;
    int d;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int digit;
        cin >> digit;
        arr.push_back(digit);
    }
    cin >> d;
    cout << elementInArray(arr, d);
}