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
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 1;
    vector<int> cut(n + 1), dfn(n + 1), low(n + 1), vis(n + 1);
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        int ch = 0;
        dfn[u] = low[u] = timer++;
        vis[u] = 1;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            if (!vis[v])
            {
                dfs(dfs, v, u);
                ch++;
                low[u] = min(low[u], low[v]);
                if (p != 0 && low[v] >= dfn[u])
                    cut[u] = 1;
            }
            else
                low[u] = min(low[u], dfn[v]);
        }

        if (p == 0 && ch >= 2)
            cut[u] = 1;
    };

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(dfs, i, 0);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cut[i])
            cnt++;
    }
    cout << cnt << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (cut[i])
            cout << i << " ";
    }
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