// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    int lps(string s)
    {
        int maxlength = s.size() - 1;
        int length = 0;
        for (int i = 0; i < maxlength; i++)
        {
            string str1 = s.substr(0, i + 1);
            string str2 = s.substr(maxlength - i);
            if (str1 == str2)
            {
                if (str1.size() > length)
                {
                    length = str1.size();
                }
            }
        }

        return length;
    }
};

// { Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
} // } Driver Code Ends