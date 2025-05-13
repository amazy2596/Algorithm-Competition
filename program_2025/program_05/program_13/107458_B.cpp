#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set<int> s;
    for (int i = 0; i < m; i++)
    {
        int v;
        cin >> v;
        s.insert(v);
    }

    vector<pair<int, int>> ans;
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        if (s.count(u) && u != *s.begin())
            ans.push_back({p, u});
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs(dfs, v, u);
        }
    };

    dfs(dfs, *s.begin(), 0);

    cout << ans.size() << "\n";
    for (auto [u, v] : ans)
        cout << u << " " << v << "\n";
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