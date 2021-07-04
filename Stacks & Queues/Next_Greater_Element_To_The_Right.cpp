// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are required to "next greater element on the right" for all elements of array
// 4. Input and output is handled for you.

// "Next greater element on the right" of an element x is defined as the first element to right of x having value greater than x.
// Note -> If an element does not have any element on it's right side greater than it, consider -1 as it's "next greater element on right"
// e.g.
// for the array [2 5 9 3 1 12 6 8 7]
// Next greater for 2 is 5
// Next greater for 5 is 9
// Next greater for 9 is 12
// Next greater for 3 is 12
// Next greater for 1 is 12
// Next greater for 12 is -1
// Next greater for 6 is 8
// Next greater for 8 is -1
// Next greater for 7 is -1
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> nge(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (st.size() > 0 && arr[i] > arr[st.top()])
        {
            int pos = st.top();
            nge[pos] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while (st.size() > 0)
    {
        int pos = st.top();
        nge[pos] = -1;
        st.pop();
    }
    for (int i : nge)
    {
        cout << i << endl;
    }
    return 0;
}