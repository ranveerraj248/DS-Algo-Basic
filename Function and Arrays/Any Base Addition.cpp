#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getSum(int b, int n1, int n2)
{
    int carry = 0;
    int digit1, digit2;
    int sum = 0;
    string ans;
    while (n1 > 0 || n2 > 0 || carry > 0)
    {
        digit1 = n1 % 10;
        digit2 = n2 % 10;
        n1 = n1 / 10;
        n2 = n2 / 10;
        sum = digit1 + digit2 + carry;
        carry = sum / b;
        sum = sum % b;
        ans += to_string(sum);
    }
    reverse(ans.begin(), ans.end());
    return stoi(ans);
}

int main()
{
    int b, n1, n2;
    cin >> b >> n1 >> n2;
    cout << getSum(b, n1, n2) << endl;
}