#include <bits/stdc++.h>

using namespace std;

int id[int(1e6) + 1];

void init(int n)

{

    for (int i = 1; i <= n; ++i)

    {

        id[i] = i;
    }
}

int root(int x)

{

    while (id[x] != x)

    {

        id[x] = id[id[x]];

        x = id[x];
    }

    return x;
}

void union1(int x, int y)

{

    int p = root(x);

    int q = root(y);

    if (p != q)

    {

        id[p] = id[q];
    }

    else
        return;
}

void giai()

{

    int n, m, u, v, k;

    long long c;

    cin >> n >> m >> k;

    vector<pair<long long, pair<int, int>>> a;

    init(n);

    for (int i = 0; i < m; ++i)

    {

        cin >> u >> v >> c;

        a.push_back({c, {u, v}});
    }

    sort(a.begin(), a.end());

    long long ans = n - 1;

    if (k <= n - 1)
        ans = 1e9;

    for (int i = 0; i < m; ++i)

    {

        pair<long long, pair<int, int>> l = a[i];

        int c = l.first;

        int u = l.second.first;

        int v = l.second.second;

        if (root(u) != root(v))

        {

            --n;

            k -= c;

            if (k >= n - 1)
                ans = n - 1;

            union1(u, v);
        }
    }

    if (n > 1 || ans > 1e7)
        ans = -1;

    cout << ans;
}

int main()

{

    int t = 1;

    while (t > 0)

    {

        giai();

        t--;
    }
}