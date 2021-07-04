// 1. You are given a base b.
// 2. You are given two numbers n1 and n2 of base b.
// 3. You are required to subtract n1 from n2 and print the value.
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getDifference(int b, int n1, int n2)
{
    int digit1, digit2;
    int difference;
    int carry = 0;
    string ans;
    while (n2 > 0)
    {
        digit1 = n2 % 10;
        digit2 = n1 % 10;
        n2 = n2 / 10;
        n1 = n1 / 10;
        digit1 += carry;
        if (digit1 < digit2)
        {
            carry = -1;
            difference = (digit1 + b) - digit2;
        }
        else
        {
            carry = 0;
            difference = digit1 - digit2;
        }
        difference %= b;
        ans += to_string(difference);
    }
    reverse(ans.begin(), ans.end());
    return stoi(ans);
}

int main()
{
    int b, n1, n2;
    cin >> b >> n1 >> n2;
    cout << getDifference(b, n1, n2);
}