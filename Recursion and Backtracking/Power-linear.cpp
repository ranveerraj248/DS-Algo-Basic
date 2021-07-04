#include <iostream>
using namespace std;

int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return 2 * power(2, n - 1);
}

int main()
{
    int n, x;
    cin >> x >> n;
    cout << power(x, n);
}
