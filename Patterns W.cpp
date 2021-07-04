#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    int n;
    cin >> n;
    int i = 1, j = 1;
    int mid = (n / 2) + 1;
    //write your code here
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (j == 1 || j == n)
            {
                cout << "*";
            }
            else if (i >= mid && (i == j || (i + j) == n + 1))
            {
                cout << "*";
            }
            cout << "\t";
        }
        cout << endl;
    }
}