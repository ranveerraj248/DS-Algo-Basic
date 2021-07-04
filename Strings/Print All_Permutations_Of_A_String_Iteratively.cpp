// 1. You are given a string.
// 2. You have to print all permutations of the given string iteratively.

#include <iostream>
#include <string>
using namespace std;
int factorial(int number)
{
    int fac = 1;
    for (int i = 2; i <= number; i++)
    {
        fac *= i;
    }
    return fac;
}
int main()
{
    string str;
    getline(cin, str);
    int n = str.length();
    int fac = factorial(n);
    for (int i = 0; i < fac; i++)
    {
        string permutation = str;
        int temp = i;
        for (int div = n; div >= 1; div--)
        {
            int q = temp / div;
            int r = temp % div;
            cout << permutation[r];
            permutation.erase(r, 1);
            temp = q;
        }
        cout << endl;
    }
    return 0;
}