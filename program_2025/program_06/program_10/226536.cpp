#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

#define ls (node << 1)
#define rs (node << 1 | 1)

struct info
{
	int mx = -inf;
	int mn = inf;
	int sum = 0;
	int ssum = 0;
	int len = 0;
	
	info () : mx(-inf), mn(inf), sum(0), ssum(0), len(0) {};
	info (int val) : mx(val), mn(val), sum(val), ssum(val * val), len(1) {};
	
	info operator+(const info &o) const
	{
		info res;
		res.mx = max(mx, o.mx);
		res.mn = min(mn, o.mn);
		res.sum = sum + o.sum;
		res.ssum = ssum + o.ssum;
		res.len = len + o.len;

		return res;
	}
};

// 区间加
struct tagAdd
{
	bool has = false;
	int add = 0;

	tagAdd() : has(false), add(0) {}
	tagAdd(int _add) : has(true), add(_add) {}

	bool empty() const
	{
		return !has;
	}

	void apply(info &a) const 
	{
		int old = a.sum;

		a.mx += add;
		a.mn += add;
		a.sum += add * a.len;
		a.ssum += 2 * add * old + add * add * a.len;
	}

	void merge(const tagAdd &o)
	{
		if (!o.has)
			return;

		has = true;
		add += o.add;
	}
};

// 区间赋值
struct tagAssign
{
	bool has = false;
	int val = 0;

	tagAssign() : has(false), val(0) {};
	tagAssign(int _val) : has(true), val(_val) {};

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

template<typename Info, typename Tag>
struct SegmentTree
{
	int n;
	vector<Info> tree;
	vector<Tag> lazy;

	SegmentTree(int _n)
	{
		n = _n;
		vector<Info> input(n + 1, Info());
		init(input);
	}

	SegmentTree(const vector<Info> &input)
	{
		n = input.size() - 1;
		init(input);
	}

	void init(const vector<Info> &input)
	{
		tree.resize(4 * n + 5, Info());
		lazy.resize(4 * n + 5, Tag());
		build(1, 1, n, input);
	}
	
	void build(int node, int start, int end, const vector<Info> &input)
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

		int mid = (start + end) >> 1;
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
		update(1, 1, n, l, r, val);
	}
	
	Info query(int l, int r)
	{
		if (l > r)
			return Info();
		return query(1, 1, n, l, r);
	}
};

#undef ls
#undef rs

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<info> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = info(x);
    }

    SegmentTree<info, tagAdd> t(a);
    while (m--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int l, r, k;
            cin >> l >> r >> k;
            t.update(l, r, k);
        }
        else 
        {
            int l, r;
            cin >> l >> r;
            cout << t.query(l, r).sum << "\n";
        }
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}