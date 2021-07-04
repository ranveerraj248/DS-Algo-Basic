#include <bits/stdc++.h>
using namespace std;
void decode(string code, string asf)
{
    if (code.size() == 0)
    {
        cout << asf;
        return;
    }
    if (code[0] == '.')
    {
        decode(code.substr(1), asf + "0");
    }
    else if (code[0] == '-' && code[1] == '.')
    {
        decode(code.substr(2), asf + "1");
    }
    else if (code[0] == '-' && code[1] == '-')
    {
        decode(code.substr(2), asf + "2");
    }
}
int main()
{
    string str;
    cin >> str;
    decode(str, "");
    return 0;
}