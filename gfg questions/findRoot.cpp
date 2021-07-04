#include <bits/stdc++.h>
using namespace std;
bool findRoots(int k, int g)
{
    double c = (-2 * g) / k;
    double d = 1 - 4 * (c);
    double sqrt_val = sqrt(abs(d));
    double root1, root2;
    root1 = (double)(-1 + sqrt_val) / (2);
    root2 = (double)(-1 - sqrt_val) / (2);
    bool root1val = false;
    bool root2val = false;
    cout << root1 << " " << root2;
    if (root1 > 0 && root1 == (int)root1)
    {
        cout << root1 << endl;
        root1val = true;
    }
    if (root2 > 0 && root2 == (int)root2)
    {
        cout << root2 << endl;
        root2val = true;
    }
    return root1val || root2val;
}
int main()
{
    int k = 3;
    int g = 10;
    cout << findRoots(5, 125);
    return 0;
}