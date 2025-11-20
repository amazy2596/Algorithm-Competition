// Problem: 【模板】最近公共祖先（LCA）
// URL: https://www.luogu.com.cn/problem/P3379
// Author: amazy
// Date: 2025-11-19 16:59:50

// #include <bits/stdc++.h>
// using namespace std;
// using i64 = int64_t;
// using i128 = __int128_t;

// struct LCA
// {
//     int n, max_log;
//     vector<vector<int>> adj, up;
//     vector<int> depth, roots;

//     LCA(int _n)
//     {
//         n = _n;
//         max_log = log2(n) + 1;
//         up.resize(n + 1, vector<int>(max_log + 1, 0));
//         adj.resize(n + 1);
//         roots.resize(n + 1, -1);
//         depth.resize(n + 1, -1);
//     }

//     void add(int u, int v)
//     {
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     void build(int root)
//     {
//         auto dfs = [&](auto dfs, int u, int p, int d, int r) -> void
//         {
//             up[u][0] = p;
//             depth[u] = d;
//             roots[u] = r;

//             for (int v : adj[u])
//             {
//                 if (v == p)
//                     continue;
//                 dfs(dfs, v, u, d + 1, r);
//             }
//         };
//         dfs(dfs, root, 0, 0, root);

//         for (int j = 1; j < max_log; j++)
//         {
//             for (int i = 1; i <= n; i++)
//             {
//                 if (up[i][j - 1] == 0)
//                     continue;

//                 up[i][j] = up[up[i][j - 1]][j - 1];
//             }
//         }
//     }

//     int query(int u, int v)
//     {
//         if (roots[u] != roots[v])
//             return -1;

//         if (depth[u] < depth[v])
//             swap(u, v);

//         for (int j = max_log - 1; j >= 0; j--)
//         {
//             if (depth[u] - (1ll << j) >= depth[v])
//                 u = up[u][j];
//         }

//         if (u == v)
//             return u;

//         for (int j = max_log - 1; j >= 0; j--)
//         {
//             if (up[u][j] != up[v][j])
//             {
//                 u = up[u][j];
//                 v = up[v][j];
//             }
//         }

//         return up[u][0];
//     }
// };

// void solve()
// {
//     int n, m, s;
//     cin >> n >> m >> s;
//     LCA lca(n + 1);
//     for (int i = 0; i < n - 1; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         lca.add(u, v);
//     }
//     lca.build(s);

//     while (m--)
//     {
//         int u, v;
//         cin >> u >> v;
//         cout << lca.query(u, v) << "\n";
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cout.tie(nullptr);
//     cin.tie(nullptr);
//     int T = 1;
//     // cin >> T;
//     while (T--)
//         solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct HLD
{
    int n;
    int id = 0;
    vector<vector<int>> adj;

    vector<int> fa;
    vector<int> deep;
    vector<int> siz;
    vector<int> son;

    vector<int> dfn;
    vector<int> rev;
    vector<int> top;

    HLD(int _n) : n(_n)
    {
        adj.resize(n + 1);
        fa.resize(n + 1, -1);
        deep.resize(n + 1);
        siz.resize(n + 1);
        son.resize(n + 1, 0);

        dfn.resize(n + 1);
        rev.resize(n + 1);
        top.resize(n + 1); 
    }

    void build(int root = 1)
    {
        id = 0;
        dfs1(root, -1, 0);
        dfs2(root, root);
    }

    void add(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs1(int u, int p, int d)
    {
        fa[u] = p;
        deep[u] = d;
        siz[u] = 1;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs1(v, u, d + 1);
            if (siz[v] > siz[son[u]]) son[u] = v;
            siz[u] += siz[v];
        }
    }

    void dfs2(int u, int t)
    {
        top[u] = t;
        dfn[u] = id++;
        rev[dfn[u]] = u;
        if (son[u]) dfs2(son[u], t);
        for (auto v : adj[u])
        {
            if (v == fa[u] || v == son[u])
                continue;
            dfs2(v, v);
        }
    }

    int dist(int u, int v) 
    {
        return deep[u] + deep[v] - 2 * deep[lca(u, v)];
    }

    int lca(int u, int v) 
    {
        while (top[u] != top[v]) 
        {
            if (deep[top[u]] < deep[top[v]]) 
                swap(u, v);
            u = fa[top[u]];
        }
        return deep[u] < deep[v] ? u : v;
    }

    int kth(int u, int k) 
    {
        if (k < 0) return -1;
        if (deep[u] < k) return -1;
        while (u != -1)
        {
            int d = dfn[u] - dfn[top[u]];
            if (k <= d) return rev[dfn[u] - k];

            k -= d + 1;
            u = fa[top[u]];
        }

        return -1;
    }

    bool is_anc(int u, int v) 
    {
        return dfn[u] <= dfn[v] && dfn[v] < dfn[u] + siz[u];
    }

    vector<pair<int,int>> vtree(vector<int> nodes, int root = 1) 
    {
        auto cmp = [&](int x, int y) { return dfn[x] < dfn[y]; };
        sort(nodes.begin(), nodes.end(), cmp);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

        vector<int> all = nodes;
        for (int i = 1; i < nodes.size(); i++) all.push_back(lca(nodes[i - 1], nodes[i]));
        sort(all.begin(), all.end(), cmp);
        all.erase(unique(all.begin(), all.end()), all.end());

        vector<pair<int,int>> edges;
        vector<int> st;
        for (int v : all) 
        {
            if (st.empty()) 
            { 
                st.push_back(v); 
                continue; 
            }
            while (!st.empty() && !is_anc(st.back(), v)) 
                st.pop_back();
            edges.emplace_back(st.back(), v);
            st.push_back(v);
        }
        return edges;
    }
};

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    HLD hld(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        hld.add(u, v);
    }
    hld.build(s);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        cout << hld.lca(u, v) << "\n";
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