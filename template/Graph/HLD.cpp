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
struct HLD
{
    int n;
    int id = 0;
    vector<vector<int>> adj;

    vector<int> fa;
    vector<int> hs;
    vector<int> deep;
    vector<int> siz;

    vector<int> dfn;
    vector<int> seg;
    vector<int> top;

    HLD(int _n) : n(_n)
    {
        adj.resize(n);
        fa.resize(n);
        deep.resize(n);
        siz.resize(n);
        hs.resize(n, -1);

        dfn.resize(n);
        seg.resize(n);
        top.resize(n); 
    }

    void work(int root = 0)
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
        int mx = 0;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs1(v, u, d + 1);
            if (siz[v] > mx)
            {
                hs[u] = v;
                mx = siz[v];
            }
            siz[u] += siz[v];
        }
    }

    void dfs2(int u, int t)
    {
        top[u] = t;
        seg[id] = u;
        dfn[u] = id++;
        if (hs[u] != -1)    
            dfs2(hs[u], t);
        for (auto v : adj[u])
        {
            if (v == fa[u] || v == hs[u])
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
        if (deep[u] < k)
            return -1;

        while (k) 
        {
            int t = fa[top[u]];
            if (deep[u] - deep[t] <= k) 
            {
                k -= deep[u] - deep[t];
                u = t;
            } else
                return seg[dfn[u] - k];
        }
        return seg[dfn[u]];
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