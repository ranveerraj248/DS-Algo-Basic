// 1. You are given a string.
// 2. You have to compress the given string in the following two ways -
//    First compression -> The string should be compressed such that consecutive duplicates of characters are replaced with a single character.
//    For "aaabbccdee", the compressed string will be "abcde".
//    Second compression -> The string should be compressed such that consecutive duplicates of characters are replaced with the character and followed by the number of consecutive duplicates.
//    For "aaabbccdee", the compressed string will be "a3b2c2de2".

#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main()
{
    string str;
    string comp1 = "", comp2 = "";
    getline(cin, str);
    queue<char> que;
    que.push(str[0]);
    int count = 1;
    for (int i = 1; i <= str.length(); i++)
    {
        if (str[i] == que.front())
        {
            count++;
        }
        else
        {
            comp1 = comp1 + que.front();
            comp2 = comp2 + que.front();
            if (count > 1)
            {
                comp2 = comp2 + to_string(count);
            }
            count = 1;
            que.pop();
            que.push(str[i]);
        }
    }
    cout << comp1 << endl;
    cout << comp2 << endl;
    return 0;
}