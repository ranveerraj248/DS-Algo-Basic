// 1. You are given a number n, representing the count of items.
// 2. You are given n numbers, representing the values of n items.
// 3. You are given n numbers, representing the weights of n items.
// 3. You are given a number "cap", which is the capacity of a bag you've.
// 4. You are required to calculate and print the maximum value that can be created in the bag without overflowing it's capacity.
// Note1 -> Items can be added to the bag even partially. But you are not allowed to put same items again and again to the bag.
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2)
{
    double ratio1 = (double)p1.first / p1.second;
    double ratio2 = (double)p2.first / p2.second;
    return ratio1 > ratio2;
}
int main()
{
    int n;
    cin >> n;
    vector<int> value(n);
    for (int &e : value)
    {
        cin >> e;
    }
    vector<int> weight(n);
    for (int &e : weight)
    {
        cin >> e;
    }
    int maxWeight;
    cin >> maxWeight;
    vector<pair<int, int>> ration;
    for (int i = 0; i < n; i++)
    {
        ration.push_back(make_pair(value[i], weight[i]));
    }
    sort(ration.begin(), ration.end(), compare);
    double maxValue = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxWeight >= ration[i].second)
        {
            maxValue += ration[i].first;
            maxWeight -= ration[i].second;
            continue;
        }
        double vw = (double)ration[i].first / ration[i].second;
        maxValue += maxWeight * vw;
        maxWeight = 0;
        break;
    }
    cout << setprecision(1) << fixed;
    cout << maxValue;
    return 0;
}