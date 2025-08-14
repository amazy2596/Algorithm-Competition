#include <bits/stdc++.h>
using namespace std;
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
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

struct HLD
{
    int n;
    int id = 0;
    vector<vector<int>> adj;

    vector<int> fa;
    vector<int> hs;
    vector<int> deep;
    vector<int> siz;

    vector<int> in;
    vector<int> out;
    vector<int> seg;
    vector<int> top;

    HLD(int _n) : n(_n)
    {
        adj.resize(n);
        fa.resize(n);
        hs.resize(n);
        deep.resize(n);
        siz.resize(n, 1);

        in.resize(n);
        out.resize(n);
        seg.resize(n);
        top.resize(n); 
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
        in[u] = ++id;
        seg[id] = u;
        if (hs[u] != 0)
            dfs2(hs[u], t);
        for (auto v : adj[u])
        {
            if (v == fa[u] || v == hs[u])
                continue;
            dfs2(v, v);
        }
        out[u] = id;
    }

    int lca(int u, int v) 
    {
        while (top[u] != top[v]) 
        {
            if (deep[top[u]] < deep[top[v]]) 
            {
                swap(u, v);
            }
            u = fa[top[u]];
        }
        return deep[u] < deep[v] ? u : v;
    }

    void work(int root = 1)
    {
        dfs1(root, 0, 0);
        dfs2(root, root);
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
    hld.work(s);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        cout << hld.lca(u, v) << "\n";
    }
}

int main()
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