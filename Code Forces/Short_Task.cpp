// Let us denote by d(n) the sum of all divisors of the number n, i.e. d(n)=∑k|nk.

// For example, d(1)=1, d(4)=1+2+4=7, d(6)=1+2+3+6=12.

// For a given number c, find the minimum n such that d(n)=c.

// Input
// The first line contains one integer t (1≤t≤104). Then t test cases follow.

// Each test case is characterized by one integer c (1≤c≤107).

// Output
// For each test case, output:

// "-1" if there is no such n that d(n)=c;
// n, otherwise.

#include <iostream>
using namespace std;
int findN(int c)
{

    for (int i = 1; i <= c; i++)
    {
        int sum = 0;
        for (int j = 1; j <= i; j++)
        {
            if (sum <= c)
            {
                if ((i % j) == 0)
                {
                    sum += j;
                }
                if (sum == c)
                {
                    return i;
                }
            }
        }
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int c;
        cin >> c;
        cout << findN(c) << endl;
    }

    return 0;
}