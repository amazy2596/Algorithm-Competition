#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

class SegmentTree_gcd
{
    public:
        vector<int> tree, data, lazy, has_lazy;
        vector<pair<int, int>> ranges;
        int n;

        SegmentTree_gcd(vector<int> &input)
        {
            n = input.size() - 1;
            data = input;
            tree.resize(4 * n + 5, INT64_MAX);
            lazy.resize(4 * n + 5, 0);
            has_lazy.resize(4 * n + 5, 0);
            ranges.resize(4 * n + 5, {-1, -1});
            build(1, 1, n);
        }

        void build(int node, int start, int end)
        {
            ranges[node] = {start, end};
            if (start == end)
                tree[node] = data[start];
            else
            {
                int mid = (start + end) / 2;
                build(node * 2, start, mid);
                build(node * 2 + 1, mid + 1, end);
                tree[node] = __gcd(tree[node * 2], tree[node * 2 + 1]);
            }
        }

        void apply_lazy(int node, int start, int end)
        {
            if (has_lazy[node])
            {
                tree[node] = lazy[node];
                if (start != end)
                {
                    int l = node * 2, r = node * 2 + 1;
                    lazy[l] = lazy[node];
                    has_lazy[l] = 1;
                    lazy[r] = lazy[node];
                    has_lazy[r] = 1;
                }
                lazy[node] = 0;
                has_lazy[node] = 0;
            }
        }

        int query(int node, int start, int end, int l, int r)
        {
            apply_lazy(node, start, end);
            if (r < start || l > end)
                return 0;
            if (l <= start && end <= r)
                return tree[node];

            int mid = (start + end) / 2;
            int left = query(node * 2, start, mid, l, r);
            int right = query(node * 2 + 1, mid + 1, end, l, r);

            return __gcd(left, right);
        }

        void update(int node, int start, int end, int l, int r, int val)
        {
            apply_lazy(node, start, end);
            if (r < start || l > end)
                return;
            if (l <= start && end <= r)
            {
                tree[node] = val;
                lazy[node] = val;
                has_lazy[node] = 1;
                return;
            }
            int mid = (start + end) / 2;
            update(node * 2, start, mid, l, r, val);
            update(node * 2 + 1, mid + 1, end, l, r, val);
            tree[node] = __gcd(tree[node * 2], tree[node * 2 + 1]);
        }

        int query(int l, int r)
        {
            return query(1, 1, n, l, r);
        }

        void update(int l, int r, int val)
        {
            update(1, 1, n, l, r, val);
        }

        void get_range(int node)
        {
            cout << ranges[node].first << " " << ranges[node].second << "\n";
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