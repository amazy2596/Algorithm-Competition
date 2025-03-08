#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector adj(n + 1, vector<int>());
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u, v}] = w;
        mp[{v, u}] = w;
    }

    int ans = INT64_MAX;
    map<int, int> vis;
    auto dfs = [&](auto dfs, int u, int p, int cur)
    {
        if (u == n)
        {
            ans = min(ans, cur);
            return;
        }

        if (vis.contains(u))
            return;
        vis[u]++;
        
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs(dfs, v, u, cur ^ mp[{u, v}]);
        }
        vis.erase(u);
    };

    dfs(dfs, 1, 0, 0);
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