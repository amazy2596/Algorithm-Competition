// Problem: 【模板】可持久化线段树 2
// URL: https://www.luogu.com.cn/problem/P3834
// Author: amazy
// Date: 2025-11-28 13:11:40

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
    int kth(Node *u, Node *v, int start, int end, int k)
    {
        if (start == end) return start;
        int ucnt = (u && u->l) ? u->l->info.cnt : 0;
        int vcnt = (v && v->l) ? v->l->info.cnt : 0;
        int lcnt = vcnt - ucnt;
        int mid = (start + end) / 2;
        if (k <= lcnt) return kth(u ? u->l : nullptr, v ? v->l : nullptr, start, mid, k);
        else return kth(u ? u->r : nullptr, v ? v->r : nullptr, mid + 1, end, k - lcnt);
    }

    int kth(int l, int r, int k) { return kth(roots[l - 1], roots[r], 0, n - 1, k); }

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
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), all;
    for (int i = 1; i <= n; i++) cin >> a[i], all.push_back(a[i]);

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    unordered_map<int, int> id;
    for (int i = 0; i < all.size(); i++) id[all[i]] = i;
    SegmentTree segtree(all.size() + 1);
    for (int i = 1; i <= n; i++) segtree.modify(i - 1, id[a[i]], 1);
    
    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        auto res = segtree.kth(l, r, k);
        cout << all[res] << "\n";
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