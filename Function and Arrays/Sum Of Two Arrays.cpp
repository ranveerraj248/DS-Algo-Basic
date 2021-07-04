// 1. You are given a number n1, representing the size of array a1.
// 2. You are given n1 numbers, representing elements of array a1.
// 3. You are given a number n2, representing the size of array a2.
// 4. You are given n2 numbers, representing elements of array a2.
// 5. The two arrays represent digits of two numbers.
// 6. You are required to add the numbers represented by two arrays and print the
// arrays.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n1, n2;
    cin >> n1;
    vector<int> a1;
    for (int i = 0; i < n1; i++)
    {
        int digit;
        cin >> digit;
        a1.push_back(digit);
    }

    cin >> n2;
    vector<int> a2;
    for (int i = 0; i < n2; i++)
    {
        int digit;
        cin >> digit;
        a2.push_back(digit);
    }
    vector<int> sum(n1 > n2 ? n1 : n2);
    int carry = 0;
    int i = a1.size() - 1;
    int j = a2.size() - 1;
    int k = sum.size() - 1;
    while (k >= 0)
    {
        int digit = carry;
        if (i >= 0)
        {
            digit += a1[i--];
        }
        if (j >= 0)
        {
            digit += a2[j--];
        }
        carry = digit / 10;
        digit = digit % 10;
        sum[k--] = digit;
    }
    if (carry > 0)
    {
        cout << carry;
    }
    for (int digit : sum)
    {
        cout << digit;
    }
}