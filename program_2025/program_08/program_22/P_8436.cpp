// Problem: 【模板】边双连通分量
// URL: https://www.luogu.com.cn/problem/P8436
// Author: amazy
// Date: 2025-08-23 00:09:53

#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct TarjanEBCC
{
    int n, cnt = 0, ebcc_count = 0, timer = 0;
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> ebcc, nadj;
    vector<int> dfn, low, ebcc_id;
    vector<bool> bridge;
    
    TarjanEBCC(int _n) : n(_n)
    {
        adj.resize(n + 1);
        dfn.resize(n + 1);
        low.resize(n + 1);
        ebcc_id.resize(n + 1);
        ebcc.resize(1);
    }

    void add(int u, int v)
    {
        adj[u].push_back({v, cnt++});
        adj[v].push_back({u, cnt++});
    }

    void dfs(int u, int p)
    {
        dfn[u] = low[u] = ++timer;
        for (auto [v, id] : adj[u])
        {
            if (id == (p ^ 1))
                continue;

            if (!dfn[v])
            {
                dfs(v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) bridge[id] = bridge[id ^ 1] = 1;
            }
            else if (dfn[v] < dfn[u])
                low[u] = min(low[u], dfn[v]);
        }
    }

    void run()
    {
        bridge.assign(cnt, 0);
        for (int i = 1; i <= n; i++)
        {
            if (!dfn[i])
            {
                dfs(i, -1);
            }
        }
    }

    void build()
    {
        vector<int> vis(n + 1);
        auto dfs = [&](auto dfs, int u) -> void
        {
            ebcc.back().push_back(u);
            ebcc_id[u] = ebcc_count;
            vis[u] = 1;
            for (auto [v, id] : adj[u])
            {
                if (bridge[id] || vis[v])
                    continue;
                dfs(dfs, v);
            }
        };

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                ebcc_count++;
                ebcc.emplace_back();
                dfs(dfs, i);
            }
        }
    }

    void construct()
    {
        nadj.assign(ebcc_count + 1, {});
        for (int u = 1; u <= n; u++)
        {
            for (auto [v, id] : adj[u])
            {
                if (bridge[id])
                {
                    int x = ebcc_id[u];
                    int y = ebcc_id[v];
                    if (x > y) 
                    {
                        nadj[x].push_back(y);
                        nadj[y].push_back(x);
                    }
                }
            }
        }
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    TarjanEBCC tj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == v) continue;
        tj.add(u, v);
    }

    tj.run();
    tj.build();

    cout << tj.ebcc_count << "\n";
    for (int i = 1; i <= tj.ebcc_count; i++)
    {
        cout << tj.ebcc[i].size() << " ";
        for (int j = 0; j < tj.ebcc[i].size(); j++)
            cout << tj.ebcc[i][j] << " ";
        cout << "\n";
    }
}

signed main()
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