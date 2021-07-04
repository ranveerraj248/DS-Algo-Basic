#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e7 + 100;
int arr[N];
int ordinaryCount(int n)
{

    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        int number = i;
        bool flag = true;
        int curDigit;
        int prevDIgit;
        prevDIgit = number % 10;
        number = number / 10;
        while (number > 0)
        {
            curDigit = number % 10;
            if (prevDIgit != curDigit)
            {
                flag = false;
                break;
            }
            else
            {
                prevDIgit = curDigit;
                number = number / 10;
            }
        }
        if (flag)
        {
            arr[i] = arr[i - 1] + 1;
        }
        else
        {
            arr[i] = arr[i - 1];
        }
    }
    return arr[n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << ordinaryCount(n) << endl;
    }
    return 0;
}