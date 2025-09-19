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
        if (!lazy[node].empty()) return;

        lazy[node].apply(tree[ls]);
        lazy[node].apply(tree[rs]);

        lazy[ls].merge(lazy[node]);
        lazy[rs].merge(lazy[node]);

        lazy[node] = Tag();
    }
    
    void update(int node, int start, int end, int l, int r, const Tag &val)
    {
        if (end < l || start > r) return;
        if (l <= start && end <= r)
        {
            val.apply(tree[node]);
            lazy[node].merge(val);
            return;
        }
d
        pushdown(node);
        int mid = (start + end) / 2;
        if (l <= mid) update(ls, start, mid, l, r, val);
        if (mid < r) update(rs, mid + 1, end, l, r, val);
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
        if (pos <= mid) modify(ls, start, mid, pos, val);
        else if (pos > mid) modify(rs, mid + 1, end, pos, val);
        tree[node] = tree[ls] + tree[rs];
    }
    
    Info query(int node, int start, int end, int l, int r)
    {
        if (l > end || r < start) return Info();
        if (l <= start && end <= r) return tree[node];
        pushdown(node);
        int mid = (start + end) / 2;
        return query(ls, start, mid, l, r) + query(rs, mid + 1, end, l, r);
    }
    
    void update(int l, int r, const Tag &val)
    {
        if (l > r) return;
        update(0, 0, n - 1, l, r, val);
    }
    
    void modify(int pos, const Info &val)
    {
        modify(0, 0, n - 1, pos, val);
    }

    Info query(int l, int r)
    {
        if (l > r) return Info();
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
// snippet-end

// snippet-begin: SegmentTree, 动态开点
#define ls (node->l)
#define rs (node->r)

template<typename Info, typename Tag>
struct SegmentTree
{
    struct Node
    {
        Info info = Info(0);
        Tag lazy = Tag();

        Node *l = nullptr;
        Node *r = nullptr;
    };

    int n;
    Node *root;
    SegmentTree(int _n) : n(_n), root(nullptr) {}

    void newNode(Node *&node, int start, int end)
    {
        if (node) return;
        node = new Node();
        node->info.len = end - start + 1;
    }   

    void pushdown(Node *node, int start, int end)
    {
        if (node->lazy.empty() || start == end) return;

        int mid = (start + end) / 2;
        newNode(ls, start, mid);
        newNode(rs, mid + 1, end);

        node->lazy.apply(ls->info);
        ls->lazy.merge(node->lazy);

        node->lazy.apply(rs->info);
        rs->lazy.merge(node->lazy);

        node->lazy = Tag();
    }

    void pushup(Node *&node, int start, int end)
    {
        Info l = (ls ? ls->info : Info());
        Info r = (rs ? rs->info : Info());
        node->info = l + r;
        node->info.len = end - start + 1;
    }

    void update(Node *&node, int start, int end, int l, int r, const Tag &val)
    {
        if (r < start || l > end) return;
        newNode(node, start, end);

        if (l <= start && end <= r)
        {
            val.apply(node->info);
            node->lazy.merge(val);
            return;
        }

        pushdown(node, start, end);
        int mid = (start + end) / 2;
        if (l <= mid) update(ls, start, mid, l, r, val);
        if (mid < r) update(rs, mid + 1, end, l, r, val);
        pushup(node, start, end);
    }

    void modify(Node *&node, int start, int end, int pos, const Info &val)
    {
        if (pos < start || pos > end) return;
        newNode(node, start, end);

        if (start == end)
        {
            node->info = val;
            node->info.len = 1;
            node->lazy = Tag();
            return;
        }

        pushdown(node, start, end);
        int mid = (start + end) / 2;
        if (pos <= mid) 
            modify(ls, start, mid, pos, val);
        else 
            modify(rs, mid + 1, end, pos, val);
        pushup(node, start, end);
    }

    Info query(Node *node, int start, int end, int l, int r)
    {
        if (!node || r < start || l > end) return Info();
        if (l <= start && end <= r) return node->info;

        pushdown(node, start, end);
        int mid = (start + end) / 2;
        return query(ls, start, mid, l, r) + query(rs, mid + 1, end, l, r);
    }

    void update(int l, int r, const Tag &val)
    {
        if (l > r) return;
        update(root, 0, n - 1, l, r, val);
    }

    void modify(int pos, const Info &val)
    {
        modify(root, 0, n - 1, pos, val);
    }

    Info query(int l, int r)
    {
        if (l > r) return Info();
        return query(root, 0, n - 1, l, r);
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
// snippet-end:

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