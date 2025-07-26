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
    int n, m, cnt, ebcc_count;
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> ebcc, nadj;
    vector<int> dfn, low, ebcc_id;
    vector<bool> bridge;
    
    TarjanEBCC(int _n, int _m) : n(_n), m(_m), cnt(0), ebcc_count(0)
    {
        adj.resize(n + 1);
        dfn.resize(n + 1);
        low.resize(n + 1);
        ebcc_id.resize(n + 1);
        bridge.resize(2 * m + 1);
    }

    void add(int u, int v)
    {
        adj[u].push_back({v, cnt++});
        adj[v].push_back({u, cnt++});
    }

    void run()
    {
        int timer = 0;
        auto tarjan = [&](auto tarjan, int u, int p) -> void
        {
            dfn[u] = low[u] = ++timer;
            for (auto [v, id] : adj[u])
            {
                if (id == (p ^ 1))
                    continue;

                if (!dfn[v])
                {
                    tarjan(tarjan, v, id);
                    low[u] = min(low[u], low[v]);
                    if (low[v] > dfn[u])
                    {
                        bridge[id] = 1;
                        bridge[id ^ 1] = 1;
                    }
                }
                else 
                    low[u] = min(low[u], dfn[v]);
            }
        };

        for (int i = 1; i <= n; i++)
        {
            if (!dfn[i])
                tarjan(tarjan, i, -1);
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
        nadj.resize(ebcc_count + 1);
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

struct LCA
{
    int n, max_log;
    vector<vector<int>> up;
    vector<int> depth, root;

    LCA(int _n)
    {
        n = _n;
        max_log = log2(n) + 1;
        up.resize(n + 1, vector<int>(max_log + 1, 0));
        root.resize(n + 1, -1);
        depth.resize(n + 1, -1);
    }

    void build(vector<vector<int>> &adj)
    {
        auto dfs = [&](auto dfs, int u, int p, int d, int r) -> void
        {
            up[u][0] = p;
            depth[u] = d;
            root[u] = r;

            for (int v : adj[u])
            {
                if (v == p)
                    continue;
                dfs(dfs, v, u, d + 1, r);
            }
        };

        for (int i = 1; i <= n; i++)
        {
            if (depth[i] == -1)
                dfs(dfs, i, 0, 0, i);
        }

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
        if (root[u] != root[v])
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

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    TarjanEBCC tj(n, m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == v) continue;
        tj.add(u, v);
    }

    tj.run();
    tj.build();
    tj.construct();
    auto &adj = tj.nadj;
    auto &id = tj.ebcc_id;
    int N = tj.ebcc_count;

    vector<pair<int, int>> query(q);
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == v) continue;
        query.push_back({u, v});
    }

    LCA lca(N);
    lca.build(adj);
    auto &fa = lca.up;

    vector<int> diff_up(N + 1), diff_down(N + 1);
    for (auto [u, v] : query)
    {
        u = id[u];
        v = id[v];

        if (lca.root[u] != lca.root[v])
        {
            cout << "NO\n";
            return;
        }

        int root = lca.query(u, v);
        diff_up[u]++;
        diff_up[root]--;
        diff_down[v]++;
        diff_down[root]--;
    }

    vector<int> vis(N + 1);
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        vis[u] = 1;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs(dfs, v, u);
            diff_up[u] += diff_up[v];
            diff_down[u] += diff_down[v];
        }
    };

    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            dfs(dfs, i, 0);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (diff_up[i] > 0 && diff_down[i] > 0)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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