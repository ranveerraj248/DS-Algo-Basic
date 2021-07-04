//1. You are given an array(arr) of different dates in format DD-MM-YYYY.
//2. You have to sort these dates in increasing order.

#include <iostream>
#include <string>
#include <vector>

using namespace std;
void countSort(string arr[], int n, int div, int mod, int range)
{
    int freqArr[range] = {0};
    string ans[n];

    for (int i = 0; i < n; i++)
    {
        freqArr[stoi(arr[i]) / div % mod]++;
    }
    for (int i = 1; i < range; i++)
    {
        freqArr[i] = freqArr[i] + freqArr[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int pos = freqArr[stoi(arr[i]) / div % mod];
        int idx = pos - 1;
        ans[idx] = arr[i];
        freqArr[stoi(arr[i]) / div % mod]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }
}

void sortDate(string arr[], int n)
{
    countSort(arr, n, 1000000, 100, 32); // days
    countSort(arr, n, 10000, 100, 13);   // month
    countSort(arr, n, 1, 10000, 2501);   // year
}
void print(string arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sortDate(arr, n);
    print(arr, n);
    return 0;
}