#include <bits/stdc++.h>
#include <regex>
using namespace std;
void solve()
{
}
int main()
{
    string remix;
    cin >> remix;
    //replace(remix.begin(), remix.end(), "WAB", " ");
    string original = regex_replace(remix, regex("WUB"), " ");
    original = regex_replace(original, regex("[' ']{2,}"), " ");
    cout << original;
    return 0;
}