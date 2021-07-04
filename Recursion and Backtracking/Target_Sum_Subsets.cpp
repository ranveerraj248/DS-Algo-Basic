// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are given a number "tar".
// 4. Complete the body of printTargetSumSubsets function - without changing signature - to calculate and print all subsets of given elements, the contents of which sum to "tar". Use sample input and output to get more idea.

#include <iostream>
#include <vector>
#include <string>
using namespace std;
void printTargetSumSubsets(vector<int> arr, int idx, string set, int sos, int tar)
{

    if (idx == arr.size())
    {
        if (sos == tar)
        {
            cout << set << ".\n";
        }
        return;
    }
    printTargetSumSubsets(arr, idx + 1, set + to_string(arr[idx]) + ", ", sos + arr[idx], tar);
    printTargetSumSubsets(arr, idx + 1, set, sos, tar);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    printTargetSumSubsets(arr, 0, "", 0, target);
    return 0;
}