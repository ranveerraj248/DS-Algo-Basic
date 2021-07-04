#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> arr, int idx, int n)
{
    if (idx == n)
    {
        return;
    }
    display(arr, idx + 1, n);

    cout << arr[idx] << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    display(arr, 0, n);
}