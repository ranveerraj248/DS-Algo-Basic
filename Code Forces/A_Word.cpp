#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int lower = 0;
    int upper = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (islower(str[i]))
        {
            lower++;
        }
        else
        {
            upper++;
        }
    }
    if (upper > lower)
    {
        for_each(str.begin(), str.end(), [](char &c)
                 { c = toupper(c); });
    }
    else
    {
        for_each(str.begin(), str.end(), [](char &c)
                 { c = tolower(c); });
    }
    cout << str;
    return 0;
}
