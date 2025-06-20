#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector adj(n + 1, vector<int>());
    for (int v = 1; v <= n; v++)
    {
        int u;
        cin >> u;
        adj[u].push_back(v);
    }

    vector<bool> vis(n + 1, false);
    auto dfs = [&](auto dfs, int u) -> bool
    {
        if (vis[u])
            return true;
        vis[u] = true;

        for (auto v : adj[u])
        {
            if (dfs(dfs, v))
                return true;
        }

        return false;
    };

    cout << (dfs(dfs, x) ? "Yes\n" : "No\n");
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