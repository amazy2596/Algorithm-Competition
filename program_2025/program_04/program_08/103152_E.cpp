#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> val(n + 1);
    auto get = [&](auto self, int u, int p) -> void
    {
        for (auto v : adj[u])
        {
            if (v == p)
                continue;

            self(self, v, u);
            val[u] += val[v] + abs(u - v);
        }
    };

    get(get, 1, 0);
    int mx = 0;
    for (int i = 1; i <= n; i++)
        mx = max(mx, val[i]);

    int ans = 1e12;
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            
            ans = min(ans, abs(mx - abs(u - v) - val[v] - val[v]));
            dfs(dfs, v, u);
        }
    };

    dfs(dfs, 1, 0);

    cout << ans << "\n";
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