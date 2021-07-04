#include <bits/stdc++.h>
using namespace std;
bool isNearlyLucky(int number)
{
    string num = to_string(number);
    bool flag = true;
    for (char &ch : num)
    {
        if (ch == '4' || ch == '7')
        {
            continue;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}
int main()
{
    string str;
    cin >> str;
    int luckyDigits = 0;
    for (char &ch : str)
    {
        if (ch == '4' || ch == '7')
        {
            luckyDigits++;
        }
    }
    if (isNearlyLucky(luckyDigits))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}