// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are given a number x.
// 4. You are required to find the all indices at which x occurs in array a.
// 5. Return an array of appropriate size which contains all indices at which x occurs in array a.

#include <iostream>
#include <vector>
using namespace std;

vector<int> allIndices(int arr[], int x, int idx, int n, int fsf)
{

    if (idx == n)
    {
        return vector<int>(fsf);
    }
    if (arr[idx] == x)
    {
        vector<int> indices = allIndices(arr, x, idx + 1, n, fsf + 1);
        indices[fsf] = idx;
        return indices;
    }
    else
    {
        vector<int> indices = allIndices(arr, x, idx + 1, n, fsf);
        return indices;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    vector<int> indices = allIndices(arr, x, 0, n, 0);
    if (indices.size() == 0)
    {
        cout << endl;
    }
    for (int i = 0; i < indices.size(); i++)
    {
        cout << indices[i] << endl;
    }
    return 0;
}