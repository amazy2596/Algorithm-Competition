#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> r(n + 1), b(n + 1);
    auto dfs1 = [&](auto dfs1, int p, int u) -> void
    {
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs1(dfs1, u, v);
            r[u] += (s[v] == 'R') + r[v];
            b[u] += (s[v] == 'B') + b[v];
        }
    };
    dfs1(dfs1, 0, 1);

    for (int i = 1; i <= n; i++)
    {
        r[i] += s[i] == 'R';
        b[i] += s[i] == 'B';
    }

    vector<int> a(n + 1), bb(n + 1), c(n + 1), d(n + 1);
    auto dfs2 = [&](auto dfs2, int p, int u) -> void
    {
        a[u] = a[p] + (r[u] - b[u] >= 2);
        bb[u] = bb[p] + (r[u] - b[u] <= 0);

        c[u] = c[p] + (b[u] - r[u] >= 2);
        d[u] = d[p] + (b[u] - r[u] <= 0);

        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs2(dfs2, u, v);
        }
    };

    dfs2(dfs2, 0, 1);

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'R')
        {
            if (a[i] > bb[i])
                cout << 1;
            else 
                cout << 0;
        }
        else if (s[i] == 'B')
        {
            if (c[i] > d[i])
                cout << 1;
            else 
                cout << 0;
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