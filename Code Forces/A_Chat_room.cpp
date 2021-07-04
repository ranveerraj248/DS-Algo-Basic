#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    string chat = "hello";
    int j = 0;
    int match = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == chat[j])
        {
            match++;
            j++;
            if (match == 5)
            {
                break;
            }
        }
    }
    if (match == 5)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}