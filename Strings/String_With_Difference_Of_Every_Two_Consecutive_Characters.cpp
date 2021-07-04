// 1. You are given a string that contains only lowercase and uppercase alphabets.
// 2. You have to form a string that contains the difference of ASCII values of every two consecutive characters between those characters.
//    For "abecd", the answer should be "a1b3e-2c1d", as
//    'b'-'a' = 1
//    'e'-'b' = 3
//    'c'-'e' = -2
//    'd'-'c' = 1

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    string finalStr = str.substr(0, 1);
    for (int i = 1; i < str.length(); i++)
    {
        finalStr += to_string(str[i] - str[i - 1]) + str[i];
    }
    cout << finalStr;
    return 0;
}