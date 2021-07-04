// 1. You are given a number n representing number of stairs in a staircase.
// 2. You are standing at the bottom of staircase. You are allowed to climb 1 step, 2 steps or 3 steps in one move.
// 3. Complete the body of printStairPaths function - without changing signature - to print the list of all paths that can be used to climb the staircase up.
// Use sample input and output to take idea about output.

#include <iostream>
#include <string>
using namespace std;

void printStairPaths(int n, string psf)
{

    if (n == 0)
    {
        psf += "";
        cout << psf << endl;
        return;
    }
    if (n < 0)
    {
        return;
    }
    printStairPaths(n - 1, psf + "1");
    printStairPaths(n - 2, psf + "2");
    printStairPaths(n - 3, psf + "3");
}

int main()
{

    int n;
    cin >> n;
    printStairPaths(n, "");
}