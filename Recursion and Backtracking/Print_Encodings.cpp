// 1. You are given a string str of digits. (will never start with a 0)
// 2. You are required to encode the str as per following rules
//     1 -> a
//     2 -> b
//     3 -> c
//     ..
//     25 -> y
//     26 -> z
// 3. Complete the body of printEncodings function - without changing signature - to calculate and print all encodings of str.
// Use the input-output below to get more understanding on what is required
// 123 -> abc, aw, lc
// 993 -> iic
// 013 -> Invalid input. A string starting with 0 will not be passed.
// 103 -> jc
// 303 -> No output possible. But such a string maybe passed. In this case print nothing.

#include <iostream>
#include <string>
string codes[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
using namespace std;

void printEncoding(string str, string asf)
{

    if (str.length() == 0)
    {
        cout << asf << endl;
        return;
    }
    int first = stoi(str.substr(0, 1));
    int firsttwo = stoi(str.substr(0, 2));
    if (first != 0)
    {
        printEncoding(str.substr(1), asf + codes[first - 1]);
    }
    if (firsttwo > 9 && firsttwo <= 26)
    {
        printEncoding(str.substr(2), asf + codes[firsttwo - 1]);
    }
}

int main()
{
    string str;
    cin >> str;
    printEncoding(str, "");
}