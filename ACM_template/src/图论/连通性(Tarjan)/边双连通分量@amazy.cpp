#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };

struct TarjanEBCC
{
    int n, id = 0, ebcc_count = 0, timer = 0;
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> ebcc, nadj;
    vector<int> dfn, low, bel, stk;
    vector<bool> bridge, instk;
    
    TarjanEBCC(int _n) : n(_n)
    {
        instk.resize(n + 1);
        adj.resize(n + 1);
        dfn.resize(n + 1);
        low.resize(n + 1);
        bel.resize(n + 1);
        ebcc.resize(1);
    }

    void add(int u, int v)
    {
        id++;
        adj[u].push_back({v, id});
        adj[v].push_back({u, id});
    }

    void dfs(int u, int fid)
    {
        dfn[u] = low[u] = ++timer;
        stk.push_back(u);
        instk[u] = true;

        for (auto [v, eid] : adj[u])
        {
            if (eid == fid) continue;

            if (!dfn[v])
            {
                dfs(v, eid);
                low[u] = min(low[u], low[v]);

                if (low[v] > dfn[u]) 
                    bridge[eid] = true;
            }
            else if (instk[v])
                low[u] = min(low[u], dfn[v]);
        }

        if (dfn[u] == low[u])
        {
            ebcc_count++;
            ebcc.emplace_back();
            while (true)
            {
                int x = stk.back();
                stk.pop_back();
                instk[x] = false;
                bel[x] = ebcc_count;
                ebcc.back().push_back(x);
                if (x == u) break;
            }
        }
    }

    void run()
    {
        bridge.assign(id + 1, 0);
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
        nadj.assign(ebcc_count + 1, {});
        for (int u = 1; u <= n; u++)
        {
            for (auto [v, id] : adj[u])
            {
                if (bridge[id])
                {
                    int x = bel[u];
                    int y = bel[v];
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