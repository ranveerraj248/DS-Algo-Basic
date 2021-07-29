#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>

using namespace std;

int p[1000005];

int main()
{
    //
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int n;
    cin >> n;
    //
    //    for(int i=0;i<n;i++)
    //        scanf("%d",&p[i]);

    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p, p + n);

    int maxi = -1;

    for (int i = 0; i < n; i++)
    {
        // if(2*p[i]>p[n-1])  break;

        int l = 0, r = n;
        int m;
        while (l < r)
        {
            m = l + (r - l) / 2;
            if (2 * p[i] >= p[m])
                l = m + 1;
            else
                r = m;
        }

        if (l - i > maxi)
            maxi = l - i;
    }

    cout << n - maxi << endl;

    return 0;
}