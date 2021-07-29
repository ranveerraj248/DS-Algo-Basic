#include <bits/stdc++.h>
using namespace std;
bool isDivisors(string s1, string s2)
{
    if (s1.size() % s2.size() != 0)
    {
        return false;
    }
    for (int i = 0; i < s1.size(); i += s2.size())
    {
        if (s1.substr(i, s2.size()) != s2)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    set<string> divisors;
    for (int i = 1; i * i <= s1.size(); i++)
    {
        if (s1.size() % i != 0)
        {
            continue;
        }
        else
        {
            string first = s1.substr(0, i);
            string second = s1.substr(0, s1.size() / i);
            if (isDivisors(s1, first))
            {
                divisors.insert(first);
            }
            if (isDivisors(s1, second))
            {
                divisors.insert(second);
            }
        }
    }
    int ans = 0;
    for (auto &e : divisors)
    {
        if (isDivisors(s2, e))
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}