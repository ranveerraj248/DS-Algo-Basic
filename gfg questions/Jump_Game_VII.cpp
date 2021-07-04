#include <bits/stdc++.h>
using namespace std;
bool canReach(string s, int minJump, int maxJump)
{
    if (s.length() == 0)
    {
        return false;
    }
    if (s[0] == '1')
    {
        return false;
    }
    if (s[0] == '0' && s.length() == 1)
    {
        return true;
    }
    bool canReachWithMinJump = false;
    bool canReachWithMaxJump = false;
    int limit = maxJump < s.length() - 1 ? maxJump : (s.length() - 1);
    for (int i = minJump; i <= limit; i++)
    {
        string temp = s.substr(i);
        canReachWithMinJump = canReach(temp, minJump, maxJump);
        if (canReachWithMinJump)
        {
            return true;
        }
    }

    return false;
}
void solve()
{
    string s;
    cin >> s;
    int minJump;
    int maxJump;
    cin >> minJump;
    cin >> maxJump;
    cout << canReach(s, minJump, maxJump) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}