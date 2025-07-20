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

    int m = 40;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, inf));
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        for (int i = 1; i <= m; i++)
            dp[u][i] = i;

        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs(dfs, v, u);
            for (int i = 1; i <= m; i++)
            {
                int mn = inf;
                for (int j = 1; j <= m; j++)
                {
                    if (i == j)
                        continue;
                    mn = min(mn, dp[v][j]);
                }
                dp[u][i] += mn;
            }
        }
    };
    dfs(dfs, 1, 0);

    cout << *min_element(dp[1].begin(), dp[1].end());
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