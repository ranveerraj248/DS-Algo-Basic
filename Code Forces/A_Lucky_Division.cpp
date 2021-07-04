#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> luckyNumbers = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};

    int i = 0;
    while (luckyNumbers[i] <= 777)
    {
        if (n % luckyNumbers[i] == 0)
        {
            cout << "YES";
            return 0;
        }
        i++;
    }
    cout << "NO";
    return 0;
}