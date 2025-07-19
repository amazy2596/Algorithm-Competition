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
    vector<vector<int>> adj(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int k, s;
        cin >> k >> s;
        adj[k].push_back(i);
        a[i] = s;
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = a[i];
    }

    vector<int> siz(n + 1);
    auto dfs = [&](auto dfs, int u) -> void
    {
        if (adj[u].size() == 0)
            siz[u] = 1;

        for (auto v : adj[u])
        {
            dfs(dfs, v);

            for (int j = m; j >= 1; j--)
            {
                for (int k = 1; k < j; k++)
                {
                    dp[u][j + k] = max(dp[u][j + k], dp[u][j] + dp[v][k]);
                }
            }

            siz[u] += siz[v];
        }
    };
    dfs(dfs, 0);
    cout << *max_element(dp[0].begin(), dp[0].end()) << "\n";

    // vector<vector<vector<int>>> dp(n + 1);
    // for (int i = 0; i <= n; i++)
    //     dp[i].resize(adj[i].size() + 1, vector<int>(m + 2));

    // auto dfs = [&](auto dfs, int i, int j, int k) -> int
    // {
    //     if (k == 0)
    //         return 0ll;
    //     if (j == 0 || k == 1)
    //         return a[i];

    //     if (dp[i][j][k])
    //         return dp[i][j][k];

    //     int ans = dfs(dfs, i, j - 1, k);
    //     int v = adj[i][j - 1];
    //     for (int s = 1; s < k; s++)
    //         ans = max(ans, dfs(dfs, i, j - 1, k - s) + dfs(dfs, v, adj[v].size(), s));

    //     dp[i][j][k] = ans;
    //     return ans;
    // };

    // cout << dfs(dfs, 0, adj[0].size(), m + 1) << "\n";
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