#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n + 1, 0), pa(n + 1), son(n + 1);
    auto dfs = [&](auto dfs, int p, int u) -> int
    {
        pa[u] = p;
        depth[u] = 1;
        for (auto v : adj[u])
        {
            if (v != p)
            {
                dfs(dfs, u, v);
                if (depth[v] + 1 > depth[u])
                    son[u] = v;
                depth[u] = max(depth[u], depth[v] + 1);
            }
        }
        return depth[u];
    };

    dfs(dfs, 0, 1);
    int ans = depth[1];
    for (int u = 1; u <= n; u++)
    {
        if (adj[u].size() >= 3 || u == 1)
        {
            int mx = 0;
            for (auto v : adj[u])
            {
                if (v != pa[u] && v != son[u])
                    mx = max(mx, depth[v]);
            }
            ans = max(ans, depth[1] + mx - 1);
        }
    }

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