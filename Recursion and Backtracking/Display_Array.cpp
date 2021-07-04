#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> arr, int idx, int n)
{
    if (idx == n)
    {
        return;
    }
    cout << arr[idx] << endl;
    display(arr, idx + 1, n);
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
