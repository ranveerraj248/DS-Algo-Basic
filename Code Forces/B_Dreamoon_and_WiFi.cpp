#include <bits/stdc++.h>
using namespace std;
int ncr(int n, int k)
{
    int res = 1;

    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
int main()
{
    string original, modified;
    cin >> original >> modified;
    int finalPos = 0;
    for (auto &ch : original)
    {
        finalPos += ch == '+' ? 1 : -1;
    }
    int posve = 0, negve = 0, unknown = 0;
    for (char ch : modified)
    {
        if (ch == '+')
        {
            posve++;
        }
        else if (ch == '-')
        {
            negve++;
        }
        else
        {
            unknown++;
        }
    }
    int curPos = posve - negve;
    if (unknown == 0 && curPos == finalPos)
    {
        cout << fixed << setprecision(12) << 1.0;
        return 0;
    }
    else if ((unknown == 0 && curPos != finalPos) || (unknown < abs(curPos - finalPos)))
    {
        cout << fixed << setprecision(12) << 0.0;
        return 0;
    }
    int ans = ncr(unknown, (unknown + abs(curPos - finalPos)) / 2);
    int tot = 1 << unknown;
    double prob = (float)ans / (float)tot;
    cout << fixed << setprecision(12) << prob;
}