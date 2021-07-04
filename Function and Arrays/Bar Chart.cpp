#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    for (int height = max; height >= 1; height--)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= height)
            {
                cout << "*\t";
            }
            else
            {
                cout << "\t";
            }
        }
        cout << "\n";
    }
}