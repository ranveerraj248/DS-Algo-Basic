#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}
void rearrangeEvenAndOdd(vector<int> &arr, int n)
{
    // Variables
    int j = -1;

    // Quick sort method
    for (int i = 0; i < n; i++)
    {

        // If array of element
        // is odd then swap
        if (arr[i] % 2 == 0)
        {

            // increment j by one
            j++;

            // swap the element
            swap(arr[i], arr[j]);
        }
    }
}
void solve()
{
    int good = 0;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &e : arr)
    {
        cin >> e;
    }
    rearrangeEvenAndOdd(arr, arr.size());
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            int ai = arr[i];
            int aj = 2 * arr[j];
            int hcf = gcd(ai, aj);
            if (hcf > 1)
            {
                good++;
            }
        }
    }
    cout << good << endl;
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