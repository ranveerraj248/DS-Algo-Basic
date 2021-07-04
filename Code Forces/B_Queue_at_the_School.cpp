#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    string que;
    cin >> que;
    for (int i = 1; i <= t; i++)
    {
        string temp = que;
        for (int j = 0; j < que.size() - 1; j++)
        {
            if (que[j] == 'B' && que[j + 1] == 'G')
            {
                temp[j] = 'G';
                temp[j + 1] = 'B';
            }
        }
        que = temp;
    }
    cout << que;
    return 0;
}