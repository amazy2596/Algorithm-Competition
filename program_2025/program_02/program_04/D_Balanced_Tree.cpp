#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), l(n + 1), r(n + 1);
    vector adj(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    auto dfs = [&](auto dfs, int u) -> void
    {
        int mx = l[u];
        for (auto v : adj[u])
        {
            remove(adj[v].begin(), adj[v].end(), u);
            adj[v].pop_back();
            dfs(dfs, v);
            mx = max(mx, a[v]);
        }
        a[u] = min(mx, r[u]);
        for (auto v : adj[u])
            ans += max(0ll, a[v] - a[u]);
    };

    dfs(dfs, 1);
    cout << ans + a[1] << "\n";
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