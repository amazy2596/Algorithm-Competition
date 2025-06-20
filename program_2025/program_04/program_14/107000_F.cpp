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

    vector dp(n + 1, vector<int>(3));
    vector<int> pa(n + 1);
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        dp[u][0]++;
        int mn = 1e9, i;
        for (auto v : adj[u])
        {
            if (p == v)
                continue;
            dfs(dfs, v, u);
            dp[u][0] += min(dp[v][1], dp[v][2]);
            dp[u][1] += min(dp[v][1], dp[v][2]);
            dp[u][2] += dp[v][1];
            if (dp[v][0] - min(dp[v][1], dp[v][2]) < mn)
                mn = min(mn, dp[v][0] - min(dp[v][1], dp[v][2])), i = v;
        }

        if (adj[u].size() > 1 || u == 1)
            dp[u][1] += mn, pa[u] = i;
        if (adj[u].size() == 1 && u != 1)
            dp[u][1] = 1e9;
    };

    dfs(dfs, 1, 0);
    cout << min({dp[1][1], dp[1][2]}) << "\n";
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