#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int pos;
    cin >> pos;
    pos--;
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 0; i < n / 2; i++)
    {
        char arr[2];
        arr[0] = str[i];
        arr[1] = str[n - 1 - i];
        sort(arr, arr + 2);
        ans += min(arr[1] - arr[0], ('z' - arr[1] + 1 + arr[0] - 'a'));
    }
    n--;
    int mid = n / 2;
    if (pos > mid)
    {
        pos = n - pos;
    }
    int st = 0;
    int end = mid;
    while (str[st] == str[n - st] && st < n)
    {
        st++;
    }
    while (str[end] == str[n - end] && end > 0)
    {
        end--;
    }
    if (st > end)
    {
        cout << "0\n";
    }
    else
    {
        ans += min(abs(pos - st), abs(end - pos));
        ans += (end - st);
        cout << ans << endl;
    }
}