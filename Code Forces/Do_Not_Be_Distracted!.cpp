#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        char curCh = str[0];
        int arr[27] = {0};
        bool flag = true;
        for (int i = 1; i < n; i++)
        {
            if (str[i] == curCh)
            {
                continue;
            }
            else
            {
                if (arr[(curCh - 'A')] == 0)
                {
                    arr[curCh - 'A'] = 1;
                    curCh = str[i];
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if (!(arr[(curCh - 'A')] == 0))
        {
            flag = false;
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}