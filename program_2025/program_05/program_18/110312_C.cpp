#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
#define inf 1e18l
using namespace std;

struct info
{
	int mx, mn, sum, ssum;
	
	info () : mx(-inf), mn(inf), sum(0), ssum(0) {};
	info (int mx, int mn, int sum, int ssum) : mx(mx), mn(mn), sum(sum), ssum(ssum) {};
	
	info operator+(info other)
	{
		return info(max(mx, other.mx), min(mn, other.mn), sum + other.sum, ssum + other.ssum);
	}
};

struct SegmentTree
{
	int n;
	vector<info> tree;
	vector<int> data, has_lazy, lazy;
	
	SegmentTree(vector<int> &input)
	{
		data = input;
		n = data.size() - 1;
		tree.resize(4 * n + 5, info());
		lazy.resize(4 * n + 5);
		has_lazy.resize(4 * n + 5);

		build(1, 1, n);
	}
	
	void build(int node, int start, int end)
	{
		if (start == end)
		{
			tree[node] = info(data[start], data[start], data[start], data[start] * data[start]);
		}
		else 
		{
			int mid = (start + end) / 2;
			build(node * 2, start, mid);
			build(node * 2 + 1, mid + 1, end);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}
	
	void update(int node, int start, int end, int pos, int x)
	{
		if (start == end)
			tree[node] = info(x, x, x, x * x);
		else 
		{
			int mid = (start + end) / 2;
			if (pos <= mid)
				update(node * 2, start, mid, pos, x);
			else 
				update(node * 2 + 1, mid + 1, end, pos, x);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}
	
	info query(int node, int start, int end, int l, int r)
	{
		if (l > end || r < start)
			return info();
			
		if (l <= start && end <= r)
			return tree[node];
			
		int mid = (start + end) / 2;
		
		return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
	}
	
	void update(int pos, int x)
	{
		return update(1, 1, n, pos, x);
	}
	
	info query(int l, int r)
	{
		if (l > r)
			return info();
		return query(1, 1, n, l, r);
	}
};

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	SegmentTree tree(a);
	
	int id = 0;
	while (q--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int x, y;
			cin >> x >> y;
			tree.update(x, y);
		}
		else if (op == 2)
		{
			int l, r;
			cin >> l >> r;
			info t = tree.query(l, r);
			// cout << ++id << " " << t.mn << " " << t.mx << " " << t.sum << "\n";
			int len = r - l + 1;

            auto S = [&](int n)
            {
                return n * (2 * n + 1) * (n + 1) / 6;
            };

			if (len - 1 == t.mx - t.mn && t.sum == len * (t.mx + t.mn) / 2 && t.ssum == S(t.mx) - S(t.mn - 1))
				cout << "YES\n";
			else 
				cout << "NO\n";
		}
	}
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