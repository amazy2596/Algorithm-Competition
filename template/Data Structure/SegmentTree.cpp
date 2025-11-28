#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

// snippet-begin:
const i64 INF = 1e18;
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
        if (lazy[node].empty()) return;

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
    i64 mx, mn, sum, len;
    info() : mx(-INF), mn(INF), sum(0), len(0) {}
    info(i64 val) : mx(val), mn(val), sum(val), len(1) {}
};

info operator+(const info &l, const info &r)
{
    info res;
    res.mx = max(l.mx, r.mx);
    res.mn = min(l.mn, r.mn);
    res.sum = l.sum + r.sum;
    res.len = l.len + r.len;
    return res;
}

// 区间加
struct tagAdd
{
    i64 add = 0;
    tagAdd() : add(0) {}
    tagAdd(i64 _add) : add(_add) {}
    bool empty() const { return add == 0; }
    void apply(info &a) const 
    { 
        a.mx += add;
        a.mn += add;
        a.sum += add * a.len; 
    }
    void merge(const tagAdd &o)
    {
        if (o.empty()) return;
        add += o.add;
    }
};

#undef ls
#undef rs
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