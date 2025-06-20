#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    double p;
    cin >> p;

    vector adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    map<int, int> mp;
    for (int i = 0; i < m; i++)
    {
        int u;
        cin >> u;
        mp[u]++;
    }
    
    vector<int> f(n + 1), g(n + 1);
    vector<double> F(n + 1), G(n + 1);
    auto dfs = [&](auto dfs, int u, int par) -> void
    {
        if (u != 1)
        {
            if (mp.find(par) != mp.end())
                f[u] = par, g[u] = f[par];
            else 
                f[u] = f[par], g[u] = par;

            if (f[u])
                F[u] = min((double)(F[par] + 1), 1 + (1 - p) * G[f[u]] + p * G[par]);
            else 
                F[u] = 1 + F[par];

            if (g[u])
                G[u] = min((double)(G[par] + 1), 1 + (1 - p) * G[g[u]] + p * G[par]);
            else 
                G[u] = 1 + G[par];
        }
        for (auto v : adj[u])
        {
            if (v == par)
                continue;
            
            dfs(dfs, v, u);
        }
    };

    dfs(dfs, 1, 0);

    double ans = 0;
    for (int i = 1; i <= n; i++)
        ans += F[i];

    cout << fixed << setprecision(2) << ans / n << "\n";
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