// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing the height of bars in a bar chart.
// 3. You are required to find and print the area of largest rectangle in the histogram.

// e.g.
// for the array [6 2 5 4 5 1 6] -> 12
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> rightBoundary(n);
    stack<int> st;
    st.push(n - 1);
    rightBoundary[n - 1] = n;
    for (int i = n - 2; i >= 0; i--)
    {
        while (st.size() > 0 && arr[i] < arr[st.top()])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            rightBoundary[i] = n;
        }
        else
        {
            rightBoundary[i] = st.top();
        }
        st.push(i);
    }
    vector<int> leftBoundary(n);
    stack<int> st2;
    st2.push(0);
    leftBoundary[0] = -1;
    for (int i = 1; i < n; i++)
    {
        while (st2.size() > 0 && arr[i] < arr[st2.top()])
        {
            st2.pop();
        }
        if (st2.size() == 0)
        {
            leftBoundary[i] = -1;
        }
        else
        {
            leftBoundary[i] = st2.top();
        }
        st2.push(i);
    }
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int width = rightBoundary[i] - leftBoundary[i] - 1;
        int area = arr[i] * width;
        if (area > maxArea)
        {
            maxArea = area;
        }
    }
    cout << maxArea;
    return 0;
}
