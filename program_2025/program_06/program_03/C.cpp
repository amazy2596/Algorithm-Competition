#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

#define ls (node << 1)
#define rs (node << 1 | 1)

struct Info
{
	int mx = -inf;
	int mn = inf;
	int sum = 0;
	int ssum = 0;
	int len = 0;

    int idx = -1;
	
	Info () : mx(-inf), mn(inf), sum(0), ssum(0), len(0) {};
	Info (int mx, int mn, int sum, int ssum, int len) : mx(mx), mn(mn), sum(sum), ssum(ssum), len(len) {};
	
	Info operator+(const Info &o) const
	{
		Info res = Info
		(
			max(mx, o.mx), 
			min(mn, o.mn), 
			sum + o.sum, 
			ssum + o.ssum,
			len + o.len
		);

        if (mx > o.mx)
            res.idx = idx;
        else if (mx < o.mx) 
            res.idx = o.idx;
        else 
            res.idx = min(idx, o.idx);
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
		vector<int> input(n + 1, 0);
		init(input);
	}

	SegmentTree(const vector<int> &input)
	{
		n = input.size() - 1;
		init(input);
	}

	void init(const vector<int> &input)
	{
		tree.resize(4 * n + 5, info());
		lazy.resize(4 * n + 5, tag());
		build(1, 1, n, input);
	}
	
	void build(int node, int start, int end, const vector<int> &input)
	{
        tree[node].len = (end - start + 1);

		if (start == end)
		{
			int v = input[start];
			tree[node] = Info(v, v, v, v * v, 1);
            tree[node].idx = start;
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
	int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    SegmentTree<Info, TagAdd> t(n << 1);

    map<int, pair<int, int>> segment;

    for (int i = 1; i <= n;)
    {
        int l = i;
        int b = a[i];
        int r = i;
        while (r + 1 <= n && a[r] + 1 == a[r + 1])
            r++;

        t.update(b, b + r - l, 1);
        segment[l] = {r, b};
        i = r + 1;
    }

    auto split = [&](int pos)
    {
        if (pos < 1 || pos > n)
            return ;

        auto it = segment.lower_bound(pos);
        if (it == segment.begin())
            return;
        it--;
        
        int L = (*it).first;
        auto [R, b] = (*it).second;

        if (L == pos)
            return;

        if (pos > R)
            return;

        int nb = b + (pos - L);
        segment[L].first = pos - 1;
        segment[pos] = make_pair(R, nb);
    };

    for (int i = 0; i < m; i++)
    {
        Info res = t.query(1, 2 * n);
        cout << res.idx << " " << res.mx << "\n";

        int l, r, b;
        cin >> l >> r >> b;

        split(l);
        split(r + 1);


        set<int> toerase;
        auto it = segment.lower_bound(l);
        while (it != segment.end())
        {
            int L = (*it).first;
            auto [R, b] = (*it).second;

            if (L > r)
                break;
            
            t.update(b, b + R - L, -1);
            toerase.insert(L);
            it++;
        }

        for (auto L : toerase)
            segment.erase(L);

        t.update(b, b + r - l, 1);
        segment[l] = make_pair(r, b);
    }

    Info res = t.query(1, 2 * n);
    cout << res.idx << " " << res.mx << "\n";
}

signed main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--)
		solve();
	return 0;
}