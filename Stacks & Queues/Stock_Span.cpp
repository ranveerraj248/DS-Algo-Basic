// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing the prices of a share on n days.
// 3. You are required to find the stock span for n days.
// 4. Stock span is defined as the number of days passed between the current day and the first day before today when price was higher than today.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> ngeL(n);
    vector<int> ans(n);
    stack<int> st;
    for (int &e : arr)
    {
        cin >> e;
    }
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (st.size() > 0 && arr[st.top()] < arr[i])
        {
            int pos = st.top();
            ngeL[pos] = i;
            st.pop();
        }
        st.push(i);
    }
    while (st.size() > 0)
    {
        int pos = st.top();
        ngeL[pos] = -1;
        st.pop();
    }
    for (int i = 0; i < n; i++)
    {
        if (ngeL[i] == -1)
        {
            cout << i + 1 << endl;
        }
        else
        {
            cout << i - ngeL[i] << endl;
        }
    }
    return 0;
}