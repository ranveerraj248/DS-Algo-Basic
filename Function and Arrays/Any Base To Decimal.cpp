#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int baseToDecimal(int n, int b)
{
    int digit;
    int ans = 0;
    int power = 0;
    while (n > 0)
    {
        digit = n % 10;
        ans += digit * pow(b, power);
        power++;
        n = n / 10;
    }
    return ans;
}
int main()
{
    int n, b;
    cin >> n;
    cin >> b;
    cout << baseToDecimal(n, b);
    return 0;
}
