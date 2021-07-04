#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr(n);
    for (int &e : arr)
    {
        cin >> e;
    }
    pair<int, int> firstSegment, secondSegment;
    firstSegment = make_pair(0, k - 1);
    ll sum = 0LL;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    ll secondSum = sum;
    ll windowSum = sum;
    ll temp = sum;
    secondSegment = make_pair(0, k - 1);
    for (int i = k; i < n; i++)
    {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > sum)
        {
            sum = windowSum;
            firstSegment = make_pair(i - 1, i);
        }
    }
    windowSum = temp;
    for (int i = k; i < n; i++)
    {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > secondSum && i - 1 != firstSegment.second && firstSegment.first != i && firstSegment.second != i && firstSegment.first != i - 1)
        {
            //cout << windowSum << endl;
            secondSum = windowSum;
            secondSegment = make_pair(i - 1, i);
        }
    }
    cout << min(firstSegment.first, secondSegment.first) + 1 << " " << max(firstSegment.first, secondSegment.first) + 1;
    //cout << firstSegment.first + 1 << " " << secondSegment.first + 1;
    return 0;
}