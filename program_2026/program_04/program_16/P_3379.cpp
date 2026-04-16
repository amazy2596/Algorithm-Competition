// Problem: 【模板】最近公共祖先（LCA）
// URL: https://www.luogu.com.cn/problem/P3379
// Author: amazy
// Date: 2026-04-16 16:55:13

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct LCA
{
    vector<vector<int>> up;
    vector<int> depth;
    int n;

    LCA(int _n, int root, vector<vector<int>> &adj) : n(_n), depth(_n + 1), up(_n + 1, vector<int>(20)) 
    {
        auto dfs = [&](auto dfs, int u, int p, int d) -> void
        {
            depth[u] = d;
            up[u][0] = p;
            for (auto v : adj[u])
            {
                if (v == p) continue;
                dfs(dfs, v, u, d + 1);
            }
        };
        dfs(dfs, root, 0, 1);

        for (int j = 1; j < 20; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }

    int query(int u, int v)
    {
        if (depth[u] < depth[v]) swap(u, v);
        for (int j = 19; j >= 0; j--)
        {
            if (depth[up[u][j]] >= depth[v])
            {
                u = up[u][j];
            }
        }

        if (u == v) return u;
        for (int j = 19; j >= 0; j--)
        {
            if (up[u][j] != up[v][j])
            {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }
};

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LCA lca(n, s, adj);

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        cout << lca.query(x, y) << "\n";
    }
}

int main()
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