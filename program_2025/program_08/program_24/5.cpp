#include<bits/stdc++.h> 
using namespace std;
using i64 = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, int> vis;
    auto dfs = [&](auto dfs, int u, int p, int d) -> void
    {
        if (a[u] == 1)
            vis[d]++;
        for (auto v : adj[u])
        {
            if (v == p) continue;
            dfs(dfs, v, u, d + 1);
        }
    };

    for (int i = 1; i <= n; i++)
    {
        vis.clear();
        dfs(dfs, i, 0, 0);
        cout << vis.size() << "\n";
    }
}

int main( )
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