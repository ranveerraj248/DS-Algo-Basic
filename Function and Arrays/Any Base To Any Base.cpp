#include <iostream>
#include <string>
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
string decimalToBase(int n, int b)
{
    string ans;
    while (n > 0)
    {
        ans += to_string(n % b);
        n = n / b;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string baseToBase(int n, int sourceBase, int destBase)
{
    int decimalBase = baseToDecimal(n, sourceBase);
    auto ans = decimalToBase(decimalBase, destBase);
    return ans;
}
int main()
{
    int n, sourceBase, destBase;
    cin >> n;
    cin >> sourceBase;
    cin >> destBase;
    cout << baseToBase(n, sourceBase, destBase);
    return 0;
}