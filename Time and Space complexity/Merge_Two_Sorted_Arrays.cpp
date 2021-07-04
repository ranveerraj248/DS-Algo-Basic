#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B)
{
    vector<int> ans(A.size() + B.size());
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < A.size() && j < B.size())
    {
        if (A[i] <= B[j])
        {
            ans[k] = A[i];
            i++;
            k++;
        }
        else
        {
            ans[k] = B[j];
            j++;
            k++;
        }
    }
    while (i < A.size())
    {
        ans[k] = A[i];
        i++;
        k++;
    }
    while (j < B.size())
    {
        ans[k] = B[j];
        j++;
        k++;
    }
    return ans;
}

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void output(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    cin >> m;
    vector<int> B(m, 0);
    input(B);

    vector<int> ans = mergeTwoSortedArrays(A, B);
    output(ans);
    return 0;
}