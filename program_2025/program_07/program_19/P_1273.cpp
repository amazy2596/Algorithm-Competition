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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= n - m; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int v, w;
            cin >> v >> w;
            adj[i].push_back({v, w});
        }
    }

    vector<int> a(n + 1);
    for (int i = n - m + 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -inf));
    vector<int> siz(n + 1);
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        if (i >= n - m + 1)
            dp[i][1] = a[i];
    }
    auto dfs = [&](auto dfs, int u) -> void
    {
        if (adj[u].size() == 0)
            siz[u] = 1;
        for (auto [v, w] : adj[u])
        {
            dfs(dfs, v);

            for (int j = siz[u]; j >= 0; j--)
            {
                for (int k = siz[v]; k >= 1; k--)
                {
                    if (dp[u][j] == -inf || dp[v][k] == -inf)
                        continue;
                    
                    dp[u][j + k] = max(dp[u][j + k], dp[u][j] + dp[v][k] - w);
                }
            }

            siz[u] += siz[v];
        }
    };
    dfs(dfs, 1);

    for (int j = m; j >= 0; j--)
    {
        if (dp[1][j] >= 0)
        {
            cout << j << "\n";
            return;
        }
    }

    cout << 0 << "\n";
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