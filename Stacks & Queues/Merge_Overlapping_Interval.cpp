// 1. You are given a number n, representing the number of time-intervals.
// 2. In the next n lines, you are given a pair of space separated numbers.
// 3. The pair of numbers represent the start time and end time of a meeting (first number is start time and second number is end time)
// 4. You are required to merge the meetings and print the merged meetings output in increasing order of start time.
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        int first;
        int second;
        cin >> first;
        cin >> second;
        arr.push_back(make_pair(first, second));
    }
    sort(arr.begin(), arr.end());
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            st.push(arr[i]);
        }
        else
        {
            pair<int, int> top = st.top();
            if (arr[i].first > top.second)
            {
                st.push(arr[i]);
            }
            else
            {
                st.pop();
                int endTime = max(top.second, arr[i].second);
                st.push(make_pair(top.first, endTime));
            }
        }
    }
    stack<pair<int, int>> ans;
    while (st.size() > 0)
    {
        ans.push(st.top());
        st.pop();
    }
    while (ans.size() > 0)
    {
        cout << ans.top().first << " " << ans.top().second << endl;
        ans.pop();
    }
    return 0;
}