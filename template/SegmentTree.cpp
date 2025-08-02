#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

const long double eps = 1e-12;
const i64 inf = 1e18; 

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };

#define ls (node * 2 + 1)
#define rs (node * 2 + 2)

template<typename Info, typename Tag>
struct SegmentTree
{
	int n;
	vector<Info> tree;
	vector<Tag> lazy;

	SegmentTree(int _n) : n(_n)
	{
		init(vector<Info>(n, Info(0)));
	}

	SegmentTree(const vector<Info> &input) : n(input.size())
	{
		init(input);
	}

	void init(const vector<Info> &input)
	{
		tree.resize(4 * n + 5, Info());
		lazy.resize(4 * n + 5, Tag());
		build(0, 0, n - 1, input);
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
	i64 mx = -inf;
	i64 mn = inf;
	i64 sum = 0;
	i64 ssum = 0;
	int len = 0;
	
	info () : mx(-inf), mn(inf), sum(0), ssum(0), len(0) {};
	info (i64 val) : mx(val), mn(val), sum(val), ssum(val * val), len(1) {};
	
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

// 区间加乘
struct tagAddMul
{
    i64 add = 0, mul = 1;

    tagAddMul() : add(0), mul(1) {}
    tagAddMul(i64 _add, i64 _mul) : add(_add), mul(_mul) {}

    bool empty() const 
    {
        return mul == 1 && add == 0;
    }

    void apply(info &o) const 
    {
        i64 old_sum = o.sum;
        i64 old_ssum = o.ssum;

        o.mx = o.mx * mul + add;
        o.mn = o.mn * mul + add;

        o.sum = old_sum * mul + add * o.len;
        o.ssum = old_ssum * mul * mul + 2 * old_sum * mul * add + o.len * add * add;
    }

    void merge(const tagAddMul &o)
    {
        mul = mul * o.mul;
        add = add * o.mul + o.add;
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

struct tagAddMIN
{
    tagAdd tagadd;
    i64 mn = inf;

    tagAddMIN() : tagadd(), mn(inf) {}
    tagAddMIN(tagAdd _tagadd) : tagadd(_tagadd) {}
    tagAddMIN(i64 _mn) : mn(_mn) {}

    bool empty() const
    {
        return tagadd.empty() && mn == inf;
    }

    void apply(info &a) const
    {
        tagadd.apply(a);
        a.mn = min(a.mn, mn);
        a.mx = min(a.mx, mn);
    }

    void merge(const tagAddMIN &o)
    {
        tagadd.merge(o.tagadd);
        mn = min(mn + o.tagadd.add, o.mn);
    }
};

#undef ls
#undef rs

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