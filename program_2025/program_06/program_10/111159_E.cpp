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

struct Info
{
	int mx = -inf;
	int mn = inf;
	int sum = 0;
	int ssum = 0;
	int len = 0;
	
	Info () : mx(-inf), mn(inf), sum(0), ssum(0), len(0) {};
	Info (int val) : mx(val), mn(val), sum(val), ssum(val * val), len(1) {};
	
	Info operator+(const Info &o) const
	{
		Info res;
		res.mx = max(mx, o.mx);
		res.mn = min(mn, o.mn);
		res.sum = sum + o.sum;
		res.ssum = ssum + o.ssum;
		res.len = len + o.len;

		return res;
	}
};

// 区间加
struct TagAdd
{
	bool has = false;
	int add = 0;

	TagAdd() : has(false), add(0) {}
	TagAdd(int _add) : has(true), add(_add) {}

	bool empty() const
	{
		return !has;
	}

	void apply(Info &a) const 
	{
		int old = a.sum;

		a.mx += add;
		a.mn += add;
		a.sum += add * a.len;
		a.ssum += 2 * add * old + add * add * a.len;
	}

	void merge(const TagAdd &o)
	{
		if (!o.has)
			return;

		has = true;
		add += o.add;
	}
};

// 区间赋值
struct TagAssign
{
	bool has = false;
	int val = 0;

	TagAssign() : has(false), val(0) {};
	TagAssign(int _val) : has(true), val(_val) {};

	bool empty() const 
	{
		return !has;
	}

	void apply(Info &a) const
	{
		a.mx = val;
		a.mn = val;
		a.sum = val * a.len;
		a.ssum = val * val * a.len;
	}

	void merge(const TagAssign &o)
	{
		if (!o.has)
			return;

		has = true;
		val = o.val;
	}
};

template<typename info, typename tag>
struct SegmentTree
{
	int n;
	vector<info> tree;
	vector<tag> lazy;

	SegmentTree(int _n)
	{
		n = _n;
		vector<info> input(n + 1, info());
		init(input);
	}

	SegmentTree(const vector<info> &input)
	{
		n = input.size() - 1;
		init(input);
	}

	void init(const vector<info> &input)
	{
		tree.resize(4 * n + 5, info());
		lazy.resize(4 * n + 5, tag());
		build(1, 1, n, input);
	}
	
	void build(int node, int start, int end, const vector<info> &input)
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

			lazy[node] = tag();
		}
	}
	
	void update(int node, int start, int end, int l, int r, const tag &val)
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
	
	info query(int node, int start, int end, int l, int r)
	{
		if (l > end || r < start)
			return info();
			
		if (l <= start && end <= r)
			return tree[node];

		pushdown(node);
			
		int mid = (start + end) / 2;
		return query(ls, start, mid, l, r) + query(rs, mid + 1, end, l, r);
	}
	
	void update(int l, int r, const tag &val)
	{
		update(1, 1, n, l, r, val);
	}
	
	info query(int l, int r)
	{
		if (l > r)
			return info();
		return query(1, 1, n, l, r);
	}
};

#undef ls
#undef rs

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    SegmentTree<Info, TagAssign> seg1(n + 1), seg2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        seg1.update(i, i, a[i] * i);
        seg2.update(i, i, a[i] * (n - i + 1));
    }

    int ans = inf;
    int l = 0, r = 1;
    map<int, int> mp;
    while (r <= n)
    {
        if (!mp[a[r - 1]])
        {
            mp[a[r - 1]] = r - 1;
            if (l == 0)
                ans = min(ans, seg2.query(1, r).mn);
            else 
                ans = min(ans, seg1.query(l, n).mn + seg2.query(1, r).mn);
        }
        else 
        {
            l = max(l, mp[a[r - 1]]);
            ans = min(ans, seg1.query(l, n).mn + seg2.query(1, r).mn);
            mp[a[r - 1]] = r - 1;
        }
        r++;
    }

    if (mp[a[n]])
        l = max(l, mp[a[n]]);
    if (!l)
        ans = 0;
    else 
        ans = min(ans, seg1.query(l, n).mn);

    cout << ans << "\n";
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