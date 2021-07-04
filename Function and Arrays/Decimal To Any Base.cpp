#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
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
int main()
{
    int n, b;
    cin >> n;
    cin >> b;
    cout << decimalToBase(n, b);
    return 0;
}