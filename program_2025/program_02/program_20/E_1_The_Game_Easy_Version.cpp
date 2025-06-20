#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    vector adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dfn(n + 1), low(n + 1), dfsOrder(n + 1);
    int timer = 0;

    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        dfn[u] = ++timer;
        dfsOrder[timer] = u;

        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(dfs, v, u);
        }

        low[u] = timer;
    };

    dfs(dfs, 1, 0);

    vector<int> pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++)
        pre[i] = max(pre[i - 1], w[dfsOrder[i]]);
    for (int i = n; i >= 1; i--)
        suf[i] = max(suf[i + 1], w[dfsOrder[i]]);

    int ans = 0, w_mx = -1;
    for (int u = 1; u <= n; u++)
    {
        int l = dfn[u], r = low[u];
        int temp = -1;

        if (l >= 1)
            temp = max(temp, pre[l - 1]);
        if (r <= n)
            temp = max(temp, suf[r + 1]);

        if (temp > w[u])
        {
            if (w[u] > w_mx)
            {
                ans = u;
                w_mx = w[u];
            }
        }
    }

    cout << ans << "\n";
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