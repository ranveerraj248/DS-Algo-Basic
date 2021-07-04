// 1. You are given a string str.
// 2. Complete the body of printSS function - without changing signature - to calculate and print all subsequences of str.
// Use sample input and output to take idea about subsequences.
#include <iostream>
#include <string>
using namespace std;

void printSS(string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    string current = ques.substr(0, 1);
    string remaining = ques.substr(1);
    printSS(remaining, ans + current);
    printSS(remaining, ans + "");
}

int main()
{
    string str;
    cin >> str;
    printSS(str, "");
}