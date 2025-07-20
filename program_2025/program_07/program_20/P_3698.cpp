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
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(k + 1));
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        dp[u][0][0] = 1;
        dp[u][0][1] = 1;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs(dfs, v, u);

            for (int i = k; i >= 0; i--)
            {
                for (int j = k; j >= 0; j--)
                {
                    if (i + j + 1 <= k)
                        dp[u][i + j + 1][1] = max(dp[u][i + j + 1][1], dp[u][i][0] + dp[v][j][1]);
                    if (i + j + 2 <= k)
                    {
                        dp[u][i + j + 2][0] = max(dp[u][i + j + 2][0], dp[u][i][0] + dp[v][j][0]);
                        dp[u][i + j + 2][1] = max(dp[u][i + j + 2][1], dp[u][i][1] + dp[v][j][0]);
                    }
                        
                }
            }
        }

        for (int i = 1; i <= k; i++)
        {
            dp[u][i][0] = max(dp[u][i][0], dp[u][i - 1][0]);
            dp[u][i][1] = max(dp[u][i][1], dp[u][i - 1][1]);
        }
    };

    dfs(dfs, 0, -1);
    cout << dp[0][k][1] << "\n";
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