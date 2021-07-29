#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int temp = n;
    while (n > 0)
    {
        int count = temp;
        while (count > 0)
        {
            for (int i = 0; i < n; i++)
            {
                cout << count;
            }
            count--;
        }
        cout << endl;
        n--;
    }
}