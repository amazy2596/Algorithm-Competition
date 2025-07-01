#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct LCA
{
    int n, max_log;
    vector<vector<int>> up;
    vector<int> depth;

    LCA(int _n)
    {
        n = _n;
        max_log = log2(n) + 1;
        up.resize(n + 1, vector<int>(max_log + 1, 0));
        depth.resize(n + 1);
    }

    void build(int root, vector<vector<int>> &adj)
    {
        auto dfs = [&](auto dfs, int u, int p, int d) -> void
        {
            up[u][0] = p;
            depth[u] = d;

            for (int v : adj[u])
            {
                if (v == p)
                    continue;
                dfs(dfs, v, u, d + 1);
            }
        };

        dfs(dfs, root, 0, 0);

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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> adj(n + 1);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u, v}] = wt;
        mp[{v, u}] = wt;
    }

    vector<int> down(n + 1), up(n + 1), sumdown(n + 1);
    auto dfs1 = [&](auto dfs1, int u, int p) -> void
    {
        down[u] = a[u] - 2 * mp[{u, p}];

        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs1(dfs1, v, u);
            down[u] += down[v];
            sumdown[u] += down[v];
        }

        down[u] = max(0ll, down[u]);
    };

    dfs1(dfs1, 1, 0);

    auto dfs2 = [&](auto dfs2, int u, int p) -> void
    {
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            up[v] = max(0ll, a[u] + sumdown[u] - down[v] + up[u] - 2 * mp[{u, v}]);
            dfs2(dfs2, v, u);
        }
    };

    dfs2(dfs2, 1, 0);

    LCA lca(n);
    lca.build(1, adj);

    vector<int> nodeV(n + 1), edgeV(n + 1);
    for (int i = 1; i <= n; i++)
    {
        nodeV[i] = a[i] + sumdown[i] + up[i];
        edgeV[i] = up[i] + down[i] + mp[{i, lca.up[i][0]}];
    }

    vector<int> prenode(n + 1), preegde(n + 1);
    auto dfs3 = [&](auto dfs3, int u, int p) -> void
    {
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            prenode[v] = prenode[u] + nodeV[v];
            preegde[v] = preegde[u] + edgeV[v];

            dfs3(dfs3, v, u);
        }
    };

    dfs3(dfs3, 1, 0);

    int q;
    cin >> q;
    while (q--)
    {
        int s, x;
        cin >> s >> x;

        int root = lca.query(s, x);

        int nodev = prenode[s] + prenode[x] - 2 * prenode[root] + nodeV[root];
        int edgev = preegde[s] + preegde[x] - 2 * preegde[root];

        cout << nodev - edgev << " ";
    }

    cout << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}