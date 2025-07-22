#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> siz(n + 1, 1);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -inf));
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        dp[u][0] = 0;
        dp[u][1] = 0;
        for (auto [v, w] : adj[u])
        {
            if (v == p)
                continue;
            dfs(dfs, v, u);

            for (int j = min(k, siz[u]); j >= 0; j--)
            {
                for (int l = min(k, siz[v]); l >= 0; l--)
                {
                    if (j + l <= k)
                    {
                        int cost1 = ((k - l) * l + (n - k - siz[v] + l) * (siz[v] - l)) * w;
                        dp[u][j + l] = max(dp[u][j + l], dp[u][j] + dp[v][l] + cost1);
                    }
                }
            }

            siz[u] += siz[v];
        }
    };

    dfs(dfs, 1, 0);

    cout << dp[1][k] << "\n";
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