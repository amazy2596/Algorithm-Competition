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
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    vector<vector<int>> dp(n + 1, vector<int>(k + 1)), ans(n + 1, vector<int>(k + 1));
    auto dfs1 = [&](auto dfs, int u, int p) -> void
    {
        dp[u][0] = c[u];
        for (auto v : adj[u])
        {
            if (v == p)
                continue;

            dfs(dfs, v, u);

            for (int d = 1; d <= k; d++)
                dp[u][d] += dp[v][d - 1];
        }
    };

    dfs1(dfs1, 1, 0);

    auto dfs2 = [&](auto dfs, int u, int p) -> void
    {
        if (p == 0)
        {
            for (int d = 0; d <= k; d++)
                ans[u][d] = dp[u][d];
        }
        else 
        {
            ans[u][0] = dp[u][0];
            ans[u][1] = dp[u][1] + ans[p][0];
            for (int d = 2; d <= k; d++)
                ans[u][d] = dp[u][d] + ans[p][d - 1] - dp[u][d - 2];
        }

        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs(dfs, v, u);
        }
    };
    dfs2(dfs2, 1, 0);

    for (int i = 1; i <= n; i++)
        cout << accumulate(ans[i].begin(), ans[i].end(), 0) << "\n";
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