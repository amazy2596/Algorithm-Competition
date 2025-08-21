// Problem: [SDOI2011] 染色
// URL: https://www.luogu.com.cn/problem/P2486
// Author: amazy
// Date: 2025-08-21 20:52:14

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

#define ls (node * 2 + 1)
#define rs (node * 2 + 2)

template<typename Info, typename Tag>
struct SegmentTree
{
    int n;
    vector<Info> tree;
    vector<Tag> lazy;

    SegmentTree() {};

    SegmentTree(int _n) : n(_n)
    {
        init(vector<Info>(n, Info(0)));
    }

    template<typename T>
    SegmentTree(const vector<T> &input) : n(input.size())
    {
        init(input);
    }

    template<typename T>
    void init(const vector<T> &input)
    {
        n = input.size();
        tree.resize(4 * n + 5, Info());
        lazy.resize(4 * n + 5, Tag());
        build(0, 0, n - 1, input);
    }
    
    template<typename T>
    void build(int node, int start, int end, const vector<T> &input)
    {
        if (start == end)
        {
            tree[node] = input[start];
        }
        else 
        {
            int mid = (start + end) / 2;
            build(ls, start, mid, input);
            build(rs, mid + 1, end, input);
            tree[node] = tree[ls] + tree[rs];
        }
    }

    void pushdown(int node)
    {
        if (!lazy[node].empty())
        {
            lazy[node].apply(tree[ls]);
            lazy[node].apply(tree[rs]);

            lazy[ls].merge(lazy[node]);
            lazy[rs].merge(lazy[node]);

            lazy[node] = Tag();
        }
    }
    
    void update(int node, int start, int end, int l, int r, const Tag &val)
    {
        if (end < l || start > r)
            return ;

        if (l <= start && end <= r)
        {
            val.apply(tree[node]);
            lazy[node].merge(val);
            return;
        }

        pushdown(node);

        int mid = (start + end) / 2;
        if (l <= mid)
            update(ls, start, mid, l, r, val);
        if (mid < r)
            update(rs, mid + 1, end, l, r, val);
        
        tree[node] = tree[ls] + tree[rs];
    }
    
    Info query(int node, int start, int end, int l, int r)
    {
        if (l > end || r < start)
            return Info();
            
        if (l <= start && end <= r)
            return tree[node];

        pushdown(node);
            
        int mid = (start + end) / 2;
        return query(ls, start, mid, l, r) + query(rs, mid + 1, end, l, r);
    }
    
    void update(int l, int r, const Tag &val)
    {
        if (l > r)
            return;
        update(0, 0, n - 1, l, r, val);
    }
    
    Info query(int l, int r)
    {
        if (l > r)
            return Info();
        return query(0, 0, n - 1, l, r);
    }
};

struct info
{
    int sum = 0;
    int lc = 0;
    int rc = 0;

    info () : sum(0), lc(0), rc(0) {};
    info (int val) : sum(1), lc(val), rc(val) {};
};

info operator+(const info &l, const info &r)
{
    info res;
    if (l.sum == 0) return r;
    if (r.sum == 0) return l;

    res.sum = l.sum + r.sum - (l.rc == r.lc);
    res.lc = l.lc;
    res.rc = r.rc;

    return res;
}

// 区间赋值
struct tagAssign
{
    bool has = false;
    i64 val = 0;

    tagAssign() : has(false), val(0) {};
    tagAssign(i64 _val) : has(true), val(_val) {};

    bool empty() const 
    {
        return !has;
    }

    void apply(info &a) const
    {
        a.sum = 1;
        a.lc = val;
        a.rc = val;        
    }

    void merge(const tagAssign &o)
    {
        if (!o.has)
            return;

        has = true;
        val = o.val;
    }
};

#undef ls
#undef rs

template<typename Tag>
struct HLD
{
    int n;
    int id;
    int start;
    int capacity;
    vector<vector<int>> adj;

    vector<int> fa;
    vector<int> hs;
    vector<int> deep;
    vector<int> siz;

    vector<int> dfn;
    vector<int> seg;
    vector<int> top;

    SegmentTree<info, Tag> tree;

    HLD(int _n, int _start = 1) : n(_n), start(_start), capacity(n + start)
    {
        adj.resize(capacity);
        fa.resize(capacity);
        deep.resize(capacity);
        siz.resize(capacity);
        hs.resize(capacity, -1);

        dfn.resize(capacity);
        seg.resize(capacity);
        top.resize(capacity); 
    }

    template<typename T>
    void build(int root, vector<T> &input)
    {
        id = 0;
        dfs1(root, -1, 0);
        dfs2(root, root);

        vector<T> tmp(n, 0);
        for (int i = start; i < capacity; i++)
            tmp[dfn[i]] = input[i];
        
        tree.init(tmp);
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

    void update_path(int u, int v, const Tag &val)
    {
        while (top[u] != top[v])
        {
            if (deep[top[u]] < deep[top[v]])
                swap(u, v);

            int l = dfn[top[u]];
            int r = dfn[u];
            tree.update(l, r, val);
            u = fa[top[u]];
        }

        int l = min(dfn[u], dfn[v]);
        int r = max(dfn[u], dfn[v]);
        tree.update(l, r, val);
    }

    info query_path(int u, int v)
    {
        info res_u, res_v;

        while (top[u] != top[v])
        {
            if (deep[top[u]] > deep[top[v]])
            {
                res_u = tree.query(dfn[top[u]], dfn[u]) + res_u;
                u = fa[top[u]];
            }
            else 
            {
                res_v = tree.query(dfn[top[v]], dfn[v]) + res_v;
                v = fa[top[v]];
            }
        }

        if (deep[u] > deep[v])
            res_u = tree.query(dfn[v], dfn[u]) + res_u;
        else 
            res_v = tree.query(dfn[u], dfn[v]) + res_v;

        swap(res_u.lc, res_u.rc);
        return res_u + res_v;
    }

    void update_subtree(int u, const Tag &val)
    {
        int l = dfn[u];
        int r = dfn[u] + siz[u] - 1;
        tree.update(l, r, val);
    }

    info query_subtree(int u)
    {
        int l = dfn[u];
        int r = dfn[u] + siz[u] - 1;
        return tree.query(l, r);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> color(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> color[i];

    HLD<tagAssign> hld(n, 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        hld.add(u, v);
    }

    hld.build(1, color);
    while (q--)
    {
        char op;
        cin >> op;
        if (op == 'Q')
        {
            int u, v;
            cin >> u >> v;

            cout << hld.query_path(u, v).sum << "\n";
        }
        else if (op == 'C')
        {
            int u, v, c;
            cin >> u >> v >> c;
            
            hld.update_path(u, v, c);
        }
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