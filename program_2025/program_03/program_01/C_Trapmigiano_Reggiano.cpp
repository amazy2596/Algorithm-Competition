#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, s, e;
    cin >> n >> s >> e;
    vector adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector dist(n + 1, vector<int>());
    auto dfs = [&](auto dfs, int u, int p, int depth) -> void
    {
        dist[depth].push_back(u);
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            
            dfs(dfs, v, u, depth + 1);
        }
    };

    dfs(dfs, e, 0, 0);

    for (int i = n; i >= 0; i--)
    {
        for (int u : dist[i])
        {
            cout << u << " ";
        }
    }

    cout << "\n";
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