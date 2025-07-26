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