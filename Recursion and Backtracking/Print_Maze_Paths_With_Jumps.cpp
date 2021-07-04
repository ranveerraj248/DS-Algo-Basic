// 1. You are given a number n and a number m representing number of rows and columns in a maze.
// 2. You are standing in the top-left corner and have to reach the bottom-right corner.
// 3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..).
// 4. Complete the body of printMazePath function - without changing signature - to print the list of all paths that can be used to move from top-left to bottom-right.
// Use sample input and output to take idea about output.

#include <iostream>
#include <string>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf)
{
    int c;
    if ((sr == dr) && (sc == dc))
    {
        psf += "";
        cout << psf << endl;
        return;
    }
    if (sr > dr || sc > dc)
    {
        return;
    }
    for (int c = 1; c <= dc - sc; c++)
    {
        printMazePaths(sr, sc + c, dr, dc, psf + "h" + to_string(c));
    }
    for (int r = 1; r <= dr - sr; r++)
    {
        printMazePaths(sr + r, sc, dr, dc, psf + "v" + to_string(r));
    }
    for (int ms = 1; ms <= dr - sr && ms <= dc - sc; ms++)
    {
        printMazePaths(sr + ms, sc + ms, dr, dc, psf + "d" + to_string(ms));
    }
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}