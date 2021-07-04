// 1. You are given a number n and a number k in separate lines, representing the number of fences and number of colors.
// 2. You are required to calculate and print the number of ways in which the fences could be painted so that not more than two fences have same colors.
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vii;
int main()
{
    int fences;
    cin >> fences;
    int color;
    cin >> color;
    ll same = color * 1;
    ll diff = color * (color - 1);
    ll total = same + diff;
    for (int i = 3; i <= fences; i++)
    {
        same = diff * 1;
        diff = total * (color - 1);
        total = same + diff;
    }
    cout << total;
    return 0;
}