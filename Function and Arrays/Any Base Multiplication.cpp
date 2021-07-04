// 1. You are given a base b.
// 2. You are given two numbers n1 and n2 of base b.
// 3. You are required to multiply n1 and n2 and print the value.
#include <iostream>
using namespace std;

int getSum(int b, int n1, int n2)
{
    // write your code here
    int return_val = 0;
    int carry = 0;
    int power = 1;

    while (n1 > 0 || n2 > 0 || carry > 0)
    {
        int d1 = n1 % 10;
        int d2 = n2 % 10;
        n1 = n1 / 10;
        n2 = n2 / 10;

        int sum = d1 + d2 + carry;
        carry = sum / b;
        sum = sum % b;

        return_val += sum * power;
        power = power * 10;
    }
    return return_val;
}

int SingleDigitProduct(int b, int n1, int d2)
{
    int rv = 0;
    int carry = 0;
    int p = 1;
    while (n1 > 0 || carry > 0)
    {
        int d1 = n1 % 10;
        n1 = n1 / 10;

        int d = d1 * d2 + carry;
        carry = d / b;
        d = d % b;
        rv = rv + d * p;
        p = p * 10;
    }
    return rv;
}

int getProduct(int b, int n1, int n2)
{
    // write your code here
    int rv = 0;
    int p = 1;
    while (n2 > 0)
    {
        int d2 = n2 % 10;
        n2 = n2 / 10;
        int sprd = SingleDigitProduct(b, n1, d2);
        rv = getSum(b, rv, sprd * p);
        p = p * 10;
    }
    return rv;
}

int main()
{
    int b, n1, n2;
    cin >> b >> n1 >> n2;
    cout << getProduct(b, n1, n2) << endl;
}
