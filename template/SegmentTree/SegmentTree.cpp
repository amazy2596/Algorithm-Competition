#include <bits/stdc++.h>
using uint = uint64_t;
#define int long long
using namespace std;

const int inf = 4e18;
int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [&](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

struct info
{
	int mx, mn, sum, ssum;
	
	info () : mx(-inf), mn(inf), sum(0), ssum(0) {};
	info (int mx, int mn, int sum, int ssum) : mx(mx), mn(mn), sum(sum), ssum(ssum) {};
	
	info operator+(const info &o)
	{
		return info(
			max(mx, o.mx), 
			min(mn, o.mn), 
			sum + o.sum, 
			ssum + o.ssum
		);
	}
};

struct SegmentTree
{
	int n;
	vector<info> tree;
	// vector<int> lazy;
    // vector<bool> has_lazy;
	
	SegmentTree(vector<int> &input)
	{
		n = input.size() - 1;
		tree.resize(4 * n + 5, info());
		// lazy.resize(4 * n + 5, 0);
		// has_lazy.resize(4 * n + 5, false);
		build(1, 1, n, input);
	}
	
	void build(int node, int start, int end, vector<int> &data)
	{
		if (start == end)
		{
			tree[node] = info(data[start], data[start], data[start], data[start] * data[start]);
		}
		else 
		{
			int mid = (start + end) / 2;
			build(node * 2, start, mid, data);
			build(node * 2 + 1, mid + 1, end, data);
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