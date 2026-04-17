#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    i64 n, m, h;
    cin >> n >> m >> h;

    vector<vector<pair<int, i64>>> adj(n);
    for (int i = 1; i <= m; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }

    vector<vector<i64>> dp(1 << n, vector<i64>(n, 4e18));
    dp[1][0] = 0;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int u = 0; u < n; u++)
        {
            if (((mask >> u) & 1) == 1)
            {
                for (auto [v, x] : adj[u])
                {
                    if (((mask >> v) & 1) == 0)
                    {
                        dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + x);
                    }
                }
            }
        }
    }

    i64 ans = dp[(1 << n) - 1][n - 1];
    if (ans < h)
    {
        cout << "Yes\n";
        cout << h - ans << "\n";
    }
    else
    {
        cout << "No\n";
        cout << ans - h + 1  << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}