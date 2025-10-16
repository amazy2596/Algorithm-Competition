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

// snippet-begin:
struct TarjanSCC
{
    int n, scc_count = 0, timer = 0;
    vector<vector<int>> adj, scc, nadj;
    vector<int> dfn, low, bel, stk;
    vector<bool> instk;

    TarjanSCC(int _n) : n(_n)
    {
        instk.resize(n + 1);
        adj.resize(n + 1);
        dfn.resize(n + 1);
        low.resize(n + 1);
        bel.resize(n + 1);
        scc.resize(1);
    }

    void add(int u, int v)
    {
        adj[u].push_back(v);
    }

    void dfs(int u)
    {
        dfn[u] = low[u] = ++timer;
        stk.push_back(u);
        instk[u] = 1;

        for (auto v : adj[u])
        {
            if (!dfn[v])
            {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if (instk[v])
                low[u] = min(low[u], dfn[v]);
        }

        if (dfn[u] == low[u])
        {
            scc_count++;
            scc.emplace_back();
            while (true)
            {
                int x = stk.back();
                stk.pop_back();
                instk[x] = false;
                bel[x] = scc_count;
                scc.back().push_back(x);
                if (x == u) break;
            }
        }
    }

    void run()
    {
        for (int i = 1; i <= n; i++)
        {
            if (!dfn[i])
            {
                dfs(i);
            }
        }
    }

    void build()
    {
        nadj.resize(scc_count + 1);
        vector<pair<int, int>> e;
        for (int u = 1; u <= n; u++)
        {
            for (int v : adj[u])
            {
                if (bel[u] != bel[v])
                {
                    e.push_back({bel[u], bel[v]});
                }
            }
        }

        sort(e.begin(), e.end());
        e.erase(unique(e.begin(), e.end()), e.end());

        for (auto [u, v] : e)
            nadj[u].push_back(v);
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