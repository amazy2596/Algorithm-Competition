#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 inf = 1e18; 

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };



void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        for (int i = b[u]; i <= m; i++)
            dp[u][i] = a[u];
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs(dfs, v, u);

            for (int j = m; j >= 0; j--)
            {
                for (int k = 0; k + b[u] <= j; k++)
                {
                    dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
                }
            }
        }
    };

    dfs(dfs, 1, 0);
    cout << dp[1][m] << "\n";
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