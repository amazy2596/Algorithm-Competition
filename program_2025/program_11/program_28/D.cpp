#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

const i64 INF = 1e18;
const i64 N = (2e5 * (1 << 5));

// struct Info
// {
//     i64 mx, mn, sum;
//     Info() : mx(-INF), mn(INF), sum(0) {}
//     Info(i64 val) : mx(val), mn(val), sum(val) {}
// };

// Info operator+(const Info &l, const Info &r)
// {
//     Info res;
//     res.mx = max(l.mx, r.mx);
//     res.mn = min(l.mn, r.mn);
//     res.sum = l.sum + r.sum;
//     return res;
// }

struct Info
{
    i64 cnt;
    Info() : cnt(0) {}
    Info(i64 val) : cnt(val) {}
};

Info operator+(const Info &l, const Info &r)
{
    Info res;
    res.cnt = l.cnt + r.cnt;
    return res;
}

struct SegmentTree
{
    struct Node
    {
        Info info = Info(0);
        Node *l = nullptr;
        Node *r = nullptr;

        Node() {}
        Node(const Node &o) : info(o.info), l(o.l), r(o.r) {}
    };

    inline static Node pool[N];
    inline static int ptr = 0;

    int n;
    vector<Node*> roots;

    SegmentTree(int _n) : n(_n)
    {
        roots.push_back(nullptr);
    }

    Node* newNode() { return &pool[ptr++]; }

    Node* clone(Node *src)
    {
        Node *node = newNode();
        if (src) *node = *src;
        return node;
    }

    Node* build(int start, int end, vector<i64> &a)
    {
        Node *node = newNode();
        if (start == end)
        {
            node->info = Info(a[start]);
            return node;
        }
        int mid = (start + end) / 2;
        node->l = build(start, mid, a);
        node->r = build(mid + 1, end, a);
        pushup(node);
        return node;
    }

    void build(vector<i64> &a)
    {
        ptr = 0;
        roots.clear();
        roots.push_back(build(0, n - 1, a));
    }

    void pushup(Node *node)
    {
        Info l = (node->l ? node->l->info : Info());
        Info r = (node->r ? node->r->info : Info());
        node->info = l + r;
    }

    Node* modify(Node *prev, int start, int end, int pos, const Info &val)
    {
        Node *node = clone(prev);
        if (start == end)
        {
            // node->info = val;
            node->info.cnt += val.cnt;
            return node;
        }

        int mid = (start + end) / 2;
        if (pos <= mid) node->l = modify(prev ? prev->l : nullptr, start, mid, pos, val);
        else node->r = modify(prev ? prev->r : nullptr, mid + 1, end, pos, val);
        pushup(node);
        return node;
    }

    int modify(int version, int pos, const Info &val)
    {
        Node *root = modify(roots[version], 0, n - 1, pos, val);
        roots.push_back(root);
        return roots.size() - 1;
    }

    Info query(Node *node, int start, int end, int l, int r)
    {
        if (!node || r < start || l > end) return Info();
        if (l <= start && end <= r) return node->info;
        int mid = (start + end) / 2;
        return query(node->l, start, mid, l, r) + query(node->r, mid + 1, end, l, r);
    }

    Info query(int version, int l, int r)
    {
        return query(roots[version], 0, n - 1, l, r);
    }

    // 权值 [l, r]内第k小数
    // int kth(Node *u, Node *v, int start, int end, int k)
    // {
    //     if (start == end) return start;
    //     int ucnt = (u && u->l) ? u->l->info.cnt : 0;
    //     int vcnt = (v && v->l) ? v->l->info.cnt : 0;
    //     int lcnt = vcnt - ucnt;
    //     int mid = (start + end) / 2;
    //     if (k <= lcnt) return kth(u ? u->l : nullptr, v ? v->l : nullptr, start, mid, k);
    //     else return kth(u ? u->r : nullptr, v ? v->r : nullptr, mid + 1, end, k - lcnt);
    // }

    // int kth(int l, int r, int k) { return kth(roots[l - 1], roots[r], 0, n - 1, k); }

    // 二分 [l, r]内第一个mx >= k的位置
    // int find_first(Node *node, int start, int end, int l, int r, int k) 
    // {
    //     if (!node || r < start || l > end || node->info.mx < k) return -1;
    //     if (start == end) return start;

    //     int mid = (start + end) / 2;
    //     int res = find_first(node->l, start, mid, l, r, k);
    //     if (res != -1) return res;
    //     return find_first(node->r, mid + 1, end, l, r, k);
    // }

    // int find_first(int version, int l, int r, int k)
    // {
    //     return find_first(roots[version], 0, n - 1, l, r, k);
    // }

    int query_mex(Node *u, Node *v, Node *lca, Node *flca, int l, int r)
    {
        if (l == r) return l;
        int cnt = (u && u->l ? u->l->info.cnt : 0)
                + (v && v->l ? v->l->info.cnt : 0)
                - (lca && lca->l ? lca->l->info.cnt : 0)
                - (flca && flca->l ? flca->l->info.cnt : 0);

        int mid = (l + r) / 2;
        if (cnt == mid - l + 1) return query_mex(u ? u->r : nullptr, v ? v->r : nullptr, lca ? lca->r : nullptr, flca ? flca->r : nullptr, mid + 1, r);
        else return query_mex(u ? u->l : nullptr, v ? v->l : nullptr, lca ? lca->l : nullptr, flca ? flca->l : nullptr, l, mid);
    }
};

struct HLD
{
    int n;
    int id = 0;
    vector<vector<int>> adj;

    vector<int> fa;
    vector<int> deep;
    vector<int> siz;
    vector<int> son;

    vector<int> dfn;
    vector<int> rev;
    vector<int> top;

    HLD(int _n) : n(_n)
    {
        adj.resize(n + 1);
        fa.resize(n + 1);
        deep.resize(n + 1);
        siz.resize(n + 1);
        son.resize(n + 1, 0);

        dfn.resize(n + 1);
        rev.resize(n + 1);
        top.resize(n + 1); 
    }

    void build(int root = 1)
    {
        id = 0;
        dfs1(root, 0, 0);
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
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs1(v, u, d + 1);
            if (siz[v] > siz[son[u]]) son[u] = v;
            siz[u] += siz[v];
        }
    }

    void dfs2(int u, int t)
    {
        top[u] = t;
        dfn[u] = id++;
        rev[dfn[u]] = u;
        if (son[u]) dfs2(son[u], t);
        for (auto v : adj[u])
        {
            if (v == fa[u] || v == son[u])
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
        while (u != 0)
        {
            int d = dfn[u] - dfn[top[u]];
            if (k <= d) return rev[dfn[u] - k];

            k -= d + 1;
            u = fa[top[u]];
        }

        return -1;
    }

    bool is_anc(int u, int v) 
    {
        return dfn[u] <= dfn[v] && dfn[v] < dfn[u] + siz[u];
    }

    vector<pair<int,int>> vtree(vector<int> nodes, int root = 1) 
    {
        auto cmp = [&](int x, int y) { return dfn[x] < dfn[y]; };
        sort(nodes.begin(), nodes.end(), cmp);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

        vector<int> all = nodes;
        for (int i = 1; i < nodes.size(); i++) all.push_back(lca(nodes[i - 1], nodes[i]));
        sort(all.begin(), all.end(), cmp);
        all.erase(unique(all.begin(), all.end()), all.end());

        vector<pair<int,int>> edges;
        vector<int> st;
        for (int v : all) 
        {
            if (st.empty()) 
            { 
                st.push_back(v); 
                continue; 
            }
            while (!st.empty() && !is_anc(st.back(), v)) 
                st.pop_back();
            edges.emplace_back(st.back(), v);
            st.push_back(v);
        }
        return edges;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    HLD hld(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        hld.add(u, v);
    }
    hld.build(1);
    auto &adj = hld.adj;
    auto &fa = hld.fa;

    SegmentTree segtree(n + 1);
    vector<int> ver(n + 1);
    int id = 0;
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        ver[u] = segtree.modify(ver[p], a[u], 1);
        for (auto v : adj[u])
        {
            if (v == p) continue;
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 1, 0);

    auto &roots = segtree.roots;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        int lca = hld.lca(x, y);
        int flca = fa[lca];
        int mex = segtree.query_mex(roots[ver[x]], roots[ver[y]], roots[ver[lca]], roots[ver[flca]], 0, n);
        cout << mex << "\n";
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