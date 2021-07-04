// 1. You are given a number n.
// 2. You are given a digit d.
// 3. You are required to calculate the frequency of digit d in number n.

#include <iostream>
using namespace std;
int main()
{
    int n, d;
    cin >> n;
    cin >> d;
    int counter = 0;
    int digit, rem;
    while (n > 0)
    {
        digit = n % 10;
        if (digit == d)
        {
            counter++;
        }
        n = n / 10;
    }
    cout << counter;
}