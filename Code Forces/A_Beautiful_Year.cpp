#include <bits/stdc++.h>
using namespace std;
int main()
{
    int year;
    cin >> year;
    string str;
    while (true)
    {
        year++;
        str = to_string(year);
        if (str[0] != str[1] && str[0] != str[2] && str[0] != str[3] && str[1] != str[2] && str[1] != str[3] && str[2] != str[3])
        {
            break;
        }
    }
    cout << year;
    return 0;
}