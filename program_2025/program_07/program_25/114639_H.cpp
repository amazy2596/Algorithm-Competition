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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];

    vector<vector<int>> adj(n + 1);
    vector<int> d(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        d[v]++;
    }

    map<int, vector<int>> mp;
    vector<int> depth(n + 1);
    int mx_depth = 0;
    auto dfs = [&](auto dfs, int u, int deep) -> void
    {
        depth[u] = deep;
        mx_depth = max(mx_depth, deep);
        mp[deep].push_back(u);
        for (auto v : adj[u])
        {
            if (--d[v] == 0)
                dfs(dfs, v, deep + 1);
        }
    };
    dfs(dfs, 1, 0);

    vector<array<int, 4>> dp(n + 1, {-inf, -inf, -inf, -inf});
    dp[1][0] = k;
    for (int d = 0; d < mx_depth; d++)
    {
        for (auto u : mp[d])
        {
            for (int j = 0; j <= 3; j++)
            {
                if (dp[u][j] >= a[u])
                    dp[u][j] += b[u];
                else 
                    dp[u][j] = -inf;
            }
        }

        array<int, 4> best = {-inf, -inf, -inf, -inf};
        for (auto u : mp[d])
        {
            for (auto v : adj[u])
            {
                for (int j = 0; j <= 3; j++)
                {
                    if (dp[u][j] >= a[u])
                        dp[v][j] = max(dp[v][j], dp[u][j]);
                    best[j] = max(best[j], dp[u][j]);
                }
            }
        }

        for (auto v : mp[d + 1])
        {
            for (int j = 0; j < 3; j++)
            {
                dp[v][j + 1] = max(dp[v][j + 1], best[j]);
            }
        }
    }

    for (int i = 0; i <= 3; i++)
    {
        if (dp[n][i] >= a[n])
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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