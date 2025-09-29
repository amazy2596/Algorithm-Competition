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

    SegmentTree() {}

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

    void modify(int node, int start, int end, int pos, const Info &val)
    {
        if (start == end)
        {
            tree[node] = val;
            return;
        }

        pushdown(node);

        int mid = (start + end) / 2;
        if (pos <= mid)
            modify(ls, start, mid, pos, val);
        else if (pos > mid)
            modify(rs, mid + 1, end, pos, val);

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
    
    void modify(int pos, const Info &val)
    {
        modify(0, 0, n - 1, pos, val);
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
    i64 mx = -INF;
    i64 mn = INF;
    i64 sum = 0;
    i64 ssum = 0;
    int len = 0;
    
    info () : mx(-INF), mn(INF), sum(0), ssum(0), len(0) {};
    info (i64 val) : mx(val), mn(val), sum(val), ssum(val * val), len(1) {};
};

info operator+(const info &l, const info &r)
{
    info res;
    res.mx = max(l.mx, r.mx);
    res.mn = min(l.mn, r.mn);
    res.sum = l.sum + r.sum;
    res.ssum = l.ssum + r.ssum;
    res.len = l.len + r.len;

    return res;
}

// 区间加
struct tagAdd
{
    i64 add = 0;

    tagAdd() : add(0) {}
    tagAdd(i64 _add) : add(_add) {}

    bool empty() const
    {
        return add == 0;
    }

    void apply(info &a) const 
    {
        i64 old = a.sum;

        a.mx += add;
        a.mn += add;
        a.sum += add * a.len;
        a.ssum += 2 * add * old + add * add * a.len;
    }

    void merge(const tagAdd &o)
    {
        if (o.empty())
            return;

        add += o.add;
    }
};

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
        a.mx = val;
        a.mn = val;
        a.sum = val * a.len;
        a.ssum = val * val * a.len;
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
    int use_edge;
    vector<vector<int>> adj;

    vector<int> fa;
    vector<int> hs;
    vector<int> deep;
    vector<int> siz;

    vector<int> dfn;
    vector<int> rev;
    vector<int> top;

    SegmentTree<info, Tag> tree;

    HLD(int _n, int _start = 1) : n(_n), start(_start), capacity(n + start)
    {
        adj.resize(capacity);
        fa.resize(capacity, -1);
        deep.resize(capacity);
        siz.resize(capacity);
        hs.resize(capacity, -1);

        dfn.resize(capacity);
        rev.resize(capacity);
        top.resize(capacity); 
    }

    void build(int root)
    {
        id = 0;
        dfs1(root, -1, 0);
        dfs2(root, root);
    }

    template<typename T> 
    void init(vector<T> &input)
    {
        use_edge = 0;
        vector<T> tmp(n, 0);
        for (int i = start; i < capacity; i++)
            tmp[dfn[i]] = input[i];
        
        tree.init(tmp);
    }

    template<typename T> 
    void init(vector<tuple<int, int, T>> &input)
    {
        use_edge = 1;
        vector<T> tmp(n, 0);
        for (auto [u, v, w] : input)
        {
            if (deep[u] > deep[v])
                tmp[dfn[u]] = w;
            else 
                tmp[dfn[v]] = w;
        }

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
        dfn[u] = id++;
        rev[dfn[u]] = u;
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
        tree.update(l + use_edge, r, val);
    }

    info query_path(int u, int v)
    {
        info res;
        while (top[u] != top[v])
        {
            if (deep[top[u]] < deep[top[v]])
                swap(u, v);

            int l = dfn[top[u]];
            int r = dfn[u];
            res = res + tree.query(l, r);
            u = fa[top[u]];
        }

        int l = min(dfn[u], dfn[v]);
        int r = max(dfn[u], dfn[v]);
        res = res + tree.query(l + use_edge, r);

        return res;
    }

    void update_subtree(int u, const Tag &val)
    {
        int l = dfn[u];
        int r = dfn[u] + siz[u] - 1;
        tree.update(l + use_edge, r, val);
    }

    info query_subtree(int u)
    {
        int l = dfn[u];
        int r = dfn[u] + siz[u] - 1;
        return tree.query(l + use_edge, r);
    }
};