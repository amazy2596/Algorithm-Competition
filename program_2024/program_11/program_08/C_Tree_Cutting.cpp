#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto check = [&](int x) -> bool
    {
        int res = 0;
        auto dfs = [&](auto self, int u, int f) -> int
        {
            int sz = 1;
            for (auto v : adj[u])
                if (v != f)
                    sz += self(self, v, u);
            if (sz >= x)
                res++, sz = 0;
            return sz;
        };
        dfs(dfs, 1, 1);
        if (res > k)
            return true;
        return false;
    };
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else 
            r = mid - 1;
    }
    cout << l << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}