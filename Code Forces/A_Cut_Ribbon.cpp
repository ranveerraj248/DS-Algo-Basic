#include <bits/stdc++.h>
using namespace std;
map<int, int> myMap;
int maxPiece(int n, int a, int b, int c)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }
    if (myMap.count(n))
    {
        return myMap[n];
    }
    return myMap[n] = (1 + max(maxPiece(n - a, a, b, c), max(maxPiece(n - b, a, b, c), maxPiece(n - c, a, b, c))));
}
int main()
{
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    cout << maxPiece(n, a, b, c);
}