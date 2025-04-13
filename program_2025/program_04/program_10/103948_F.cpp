#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto check = [&](auto check, int x) -> int
    {
        vector<int> cnt(n + 1, 1);
        int res = 0;
        auto dfs = [&](auto dfs, int u, int p) -> void
        {
            for (auto v : adj[u])
            {
                if (p == v)
                    continue;
                dfs(dfs, v, u);
                cnt[u] += cnt[v];
            }
    
            if (cnt[u] > x)
                cnt[u] = 0, res++;
        };
        dfs(dfs, 1, 0);

        return res;
    };

    int l = 0, r = n + 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        int res = check(check, mid);
        if (res > k)
            l = mid + 1;
        else
            r = mid;
    }

    cout << l << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}