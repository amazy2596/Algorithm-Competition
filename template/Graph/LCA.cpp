#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

// snippet-begin:
struct LCA
{
    int n, max_log;
    vector<vector<int>> adj, up;
    vector<int> depth, roots;

    LCA(int _n)
    {
        n = _n;
        max_log = log2(n) + 1;
        up.resize(n + 1, vector<int>(max_log + 1, 0));
        adj.resize(n + 1);
        roots.resize(n + 1, -1);
        depth.resize(n + 1, -1);
    }

    void add(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void build(int root)
    {
        auto dfs = [&](auto dfs, int u, int p, int d, int r) -> void
        {
            up[u][0] = p;
            depth[u] = d;
            roots[u] = r;

            for (int v : adj[u])
            {
                if (v == p)
                    continue;
                dfs(dfs, v, u, d + 1, r);
            }
        };
        dfs(dfs, root, 0, 0, root);

        for (int j = 1; j < max_log; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (up[i][j - 1] == 0)
                    continue;

                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }

    int query(int u, int v)
    {
        if (roots[u] != roots[v])
            return -1;

        if (depth[u] < depth[v])
            swap(u, v);

        for (int j = max_log - 1; j >= 0; j--)
        {
            if (depth[u] - (1ll << j) >= depth[v])
                u = up[u][j];
        }

        if (u == v)
            return u;

        for (int j = max_log - 1; j >= 0; j--)
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
// snippet-end

void solve()
{
    
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