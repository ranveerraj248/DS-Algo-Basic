// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are required to print all subsets of arr. Each subset should be
// on separate line. For more clarity check out sample input and output.

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int digit;
        cin >> digit;
        arr.push_back(digit);
    }
    int limit = pow(2, arr.size());
    for (int i = 0; i < limit; i++)
    {
        int temp = i;
        string set = "";
        for (int j = arr.size() - 1; j >= 0; j--)
        {
            int rem = temp % 2;
            temp = temp / 2;
            if (rem == 0)
                set = "-\t" + set;
            else
                set = to_string(arr[j]) + "\t" + set;
        }
        cout << set << endl;
    }
    return 0;
}