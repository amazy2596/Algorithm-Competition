#include <bits/stdc++.h>
#define uint uint64_t
// #define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    vector<int> siz(n + 1, 0);
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs(dfs, v, u);

            auto tmp = dp[u];
            for (int i = min(k, siz[u]); i >= 0; i--)
            {
                for (int j = min(k, siz[v]); j >= 0; j--)
                {
                    if (i + j <= k)
                        tmp[i + j] = max(tmp[i + j], dp[u][i] + dp[v][j]);
                }
            }

            dp[u] = move(tmp);
            siz[u] += siz[v];
        }

        if (u != 1 && adj[u].size() == 1)
        {
            siz[u] = 1;
            dp[u][1] = a[u];
        }
        else if (siz[u] <= k)
            dp[u][siz[u]] += a[u];
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