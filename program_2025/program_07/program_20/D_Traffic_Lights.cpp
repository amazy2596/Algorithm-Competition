#include <bits/stdc++.h>
#define uint uint64_t
// #define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    array<vector<int>, 2> dp({vector<int>(n + 1, inf), vector<int>(n + 1, inf)});
    // dp[0].resize(n + 1);
    // dp[1].resize(n + 1);
    dp[0][1] = 0;
    for (int t = 0; t <= 3 * n; t++)
    {
        int cur = t % 2;
        int nxt = (t + 1) % 2;
        fill(dp[nxt].begin(), dp[nxt].end(), inf);
        for (int u = 1; u <= n; u++)
        {
            if (dp[cur][u] == inf)
                continue;

            dp[nxt][u] = min(dp[nxt][u], dp[cur][u] + 1);
            
            int v = adj[u][t % adj[u].size()];
            dp[nxt][v] = min(dp[nxt][v], dp[cur][u]);
        }

        if (dp[nxt][n] != inf)
        {
            cout << t + 1 << " " << dp[nxt][n] << "\n";
            return;
        }
    }

    // queue<pair<int, int>> q;
    // q.push({1, 0});
    // // vector<vector<int>> vis(n + 1, vector<int>(n + 1));
    // while (!q.empty())
    // {
    //     auto [u, t] = q.front();
    //     q.pop();
    //     if (t > 3 * n)
    //         continue;

    //     // if (vis[u][t % adj[u].size()])
    //         // continue;
    //     // vis[u][t % adj[u].size()] = 1;

    //     if (dp[u][t + 1] > dp[u][t] + 1)
    //     {
    //         q.push({u, t + 1});
    //         dp[u][t + 1] = dp[u][t] + 1;
    //     }

    //     int v = adj[u][t % adj[u].size()];
    //     if (dp[v][t + 1] > dp[u][t])
    //     {
    //         q.push({v, t + 1});
    //         dp[v][t + 1] = dp[u][t];
    //     }
    // }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}