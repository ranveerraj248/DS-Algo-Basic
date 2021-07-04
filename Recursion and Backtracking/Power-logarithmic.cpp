#include <iostream>
using namespace std;

int powerLogarithmic(int x, int n)
{

    if (n == 0)
    {
        return 1;
    }
    int xrn2 = powerLogarithmic(x, n / 2);
    int xrn = xrn2 * xrn2;
    if (n % 2 == 0)
    {
        return xrn;
    }
    else
        return xrn * x;
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << powerLogarithmic(x, n);
}