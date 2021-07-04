// 1. You are given a string str.
// 2. Complete the body of printPermutations function - without changing signature - to calculate and print all permutations of str.
// Use sample input and output to take idea about permutations.

#include <iostream>
#include <string>
using namespace std;

void printPermutations(string str, string asf)
{

    if (str.length() == 0)
    {
        cout << asf << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        string current = str.substr(i, 1);
        string temp = str;
        temp.erase(i, 1);
        printPermutations(temp, asf + current);
    }
}

int main()
{
    string str;
    cin >> str;
    printPermutations(str, "");
}