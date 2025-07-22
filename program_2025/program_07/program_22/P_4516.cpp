#include <bits/stdc++.h>
#define uint uint64_t
// #define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int mod = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<array<array<int, 2>, 2>>> dp(n + 1, vector<array<array<int, 2>, 2>>(k + 1, {array<int, 2>{0, 0}, array<int, 2>{0, 0}}));
    vector<int> siz(n + 1, 1);
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        dp[u][1][1][0] = 1;
        dp[u][0][0][0] = 1;

        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs(dfs, v, u);

            auto tmp = dp[u];
            for (int i = 0; i <= min(k, siz[u]); i++)
            {
                dp[u][i][0][0] = 0;
                dp[u][i][0][1] = 0;
                dp[u][i][1][0] = 0;
                dp[u][i][1][1] = 0;
            }
            for (int i = min(k, siz[u]); i >= 0; i--)
            {
                for (int j = min(k, siz[v]); j >= 0; j--)                
                {
                    if (i + j <= k)
                    {
                        dp[u][i + j][0][0] = (dp[u][i + j][0][0] + (1ll * tmp[i][0][0] * dp[v][j][0][1]) % mod) % mod;

                        dp[u][i + j][0][1] = (dp[u][i + j][0][1] + (1ll * tmp[i][0][1] * (dp[v][j][0][1] + dp[v][j][1][1])) % mod) % mod;
                        dp[u][i + j][0][1] = (dp[u][i + j][0][1] + (1ll * tmp[i][0][0] * dp[v][j][1][1]) % mod) % mod;

                        dp[u][i + j][1][0] = (dp[u][i + j][1][0] + (1ll * tmp[i][1][0] * (dp[v][j][0][0] + dp[v][j][0][1])) % mod) % mod;

                        dp[u][i + j][1][1] = (dp[u][i + j][1][1] + 1ll * tmp[i][1][0] * (dp[v][j][1][0] + dp[v][j][1][1]) % mod) % mod;
                        dp[u][i + j][1][1] = (dp[u][i + j][1][1] + (1ll * tmp[i][1][1] * (1ll * dp[v][j][0][0] + 1ll * dp[v][j][0][1] + 1ll * dp[v][j][1][0] + 1ll * dp[v][j][1][1])) % mod) % mod;
                    }
                }
            }
            
            siz[u] += siz[v];
        }
    };

    dfs(dfs, 1, 0);
    cout << (dp[1][k][1][1] + dp[1][k][0][1]) % mod << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}