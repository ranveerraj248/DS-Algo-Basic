#include <bits/stdc++.h>
using namespace std;
bool realWholeRoot(int k, int G)
{
    double b = (2 * k) - 1;

    //double c = (2 * G);
    double d = (b * b) + 8 * (G);
    double sqrt_val = sqrt(abs(d));
    double root1 = 0, root2 = 0;
    if (d > 0)
    {
        root1 = (double)(-1 + sqrt_val) / (2);
        root2 = (double)(-1 - sqrt_val) / (2);
    }
    bool root1val = false;
    bool root2val = false;
    if (root1 > 0 && root1 == (int)root1)
    {
        //cout << root1 << endl;
        root1val = true;
    }
    if (root2 > 0 && root2 == (int)root2)
    {
        //cout << root2 << endl;
        root2val = true;
    }
    return root1val || root2val;
}
int solve()
{
    int G;
    cin >> G;
    int count = 0;
    for (int k = 1; k <= G; k++)
    {
        bool positiveWhole = realWholeRoot(k, G);
        if (positiveWhole)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    int y = 1;
    while (t--)
    {
        cout << "Case #" << y << ": " << solve() << endl;
        y++;
    }
}