#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

struct DSU
{
    vector<int> f, siz;

    DSU(int n) : f(n + 1), siz(n + 1, 1)
    {
        iota(f.begin(), f.end(), 0);
    }

    int find(int x)
    {
        while (f[x] != x)
            x = f[x] = f[f[x]];
        return x;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (siz[x] < siz[y])
            swap(x, y);

        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};

void solve()
{
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x].push_back(i);
    }
    
    DSU dsu(n);
    for (auto &[key, v1] : mp)
    {
        if (mp.find(key + 1) == mp.end())
            continue;
        auto &v2 = mp[key + 1];

        for (auto a : v1)
        {
            for (auto b : v2)
            {
                dsu.merge(a, b);
            }
        }
    }

    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(dsu.find(i));

    cout << s.size() - 1 << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}