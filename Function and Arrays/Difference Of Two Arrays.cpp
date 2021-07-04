// 1. You are given a number n1, representing the size of array a1.
// 2. You are given n1 numbers, representing elements of array a1.
// 3. You are given a number n2, representing the size of array a2.
// 4. You are given n2 numbers, representing elements of array a2.
// 5. The two arrays represent digits of two numbers.
// 6. You are required to find the difference of two numbers represented by two arrays and print the arrays. a2 - a1

// Assumption - number represented by a2 is greater.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> a1, a2, ans;
    int n1, n2;
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        int digit;
        cin >> digit;
        a1.push_back(digit);
    }
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        int digit;
        cin >> digit;
        a2.push_back(digit);
    }
    int carry = 0;
    int difference;
    int i = a1.size() - 1;
    int j = a2.size() - 1;
    while (j >= 0)
    {
        int difference = 0;
        int a1value = i >= 0 ? a1[i] : 0;
        if (a2[j] + carry >= a1value)
        {
            difference = a2[j] + carry - a1value;
            carry = 0;
        }
        else
        {
            difference = a2[j] + 10 + carry - a1value;
            carry = -1;
        }

        ans.push_back(difference);
        i--;
        j--;
    }
    reverse(ans.begin(), ans.end());
    int leading0 = 0;
    for (int digit : ans)
    {
        if (leading0 == 0)
        {
            if (digit == 0)
            {
                continue;
            }
            else
                leading0++;
        }

        cout << digit << endl;
    }
    return 0;
}