// 1. You are given a string.
// 2. You have to print all palindromic substrings of the given string.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string str)
{
    string temp = str;
    reverse(temp.begin(), temp.end());
    if (temp == str)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 1; j <= str.length() - i; j++)
        {
            string curStr = str.substr(i, j);
            if (isPalindrome(curStr))
            {
                cout << curStr << endl;
            }
        }
    }
    return 0;
}