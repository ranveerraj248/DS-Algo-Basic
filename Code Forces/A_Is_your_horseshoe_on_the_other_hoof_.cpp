#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr(4);
    for (int &e : arr)
    {
        cin >> e;
    }
    int visited = -1;
    vector<int> fr(4, 0);
    for (int i = 0; i < 4; i++)
    {
        int count = 1;
        for (int j = i + 1; j < 4; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                //To avoid counting same element again
                fr[j] = visited;
            }
        }
        if (fr[i] != visited)
            fr[i] = count;
    }
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if (fr[i] != visited)
        {
            ans += fr[i] - 1;
        }
    }
    cout << ans;
    return 0;
}