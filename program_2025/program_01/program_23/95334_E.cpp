#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

class SegmentTree_mn
{
    public:
        vector<int> tree, data, lazy, has_lazy;
        vector<pair<int, int>> ranges;
        int n;

        SegmentTree_mn(vector<int> &input)
        {
            n = input.size();
            data = input;
            tree.resize(4 * n, INT64_MAX);
            lazy.resize(4 * n);
            has_lazy.resize(4 * n);
            ranges.resize(4 * n, {-1, -1});
            build(0, 0, n - 1);
        }

        void build(int node, int start, int end)
        {
            ranges[node] = {start, end};
            if (start == end)
                tree[node] = data[start];
            else
            {
                int mid = (start + end) / 2;
                build(node * 2 + 1, start, mid);
                build(node * 2 + 2, mid + 1, end);

                tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);
            }
        }

        void apply_lazy(int node, int start, int end)
        {
            if (has_lazy[node])
            {
                tree[node] = lazy[node];
                if (start != end)
                {
                    int l = node * 2 + 1, r = node * 2 + 2;

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
                return INT64_MAX;
            if (l <= start && end <= r)
                return tree[node];

            int mid = (start + end) / 2;
            int left = query(node * 2 + 1, start, mid, l, r);
            int right = query(node * 2 + 2, mid + 1, end, l, r);

            return min(left, right);
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
            update(node * 2 + 1, start, mid, l, r, val);
            update(node * 2 + 2, mid + 1, end, l, r, val);

            tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);
        }

        int query(int l, int r)
        {
            return query(0, 0, n - 1, l, r);
        }

        void update(int l, int r, int val)
        {
            update(0, 0, n - 1, l, r, val);
        }

        void get_range(int node)
        {
            cout << ranges[node].first << " " << ranges[node].second << "\n";
        }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n), pre(n), tar(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        pre[i] = i == 0 ? a[i] : pre[i - 1] + a[i];
        tar[i] = (i == 0 ? 0 : pre[i - 1]) - a[i];
    }

    SegmentTree_mn t(tar);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;

        if (l == r)
        {
            cout << 0 << "\n";
            continue;
        }

        int temp = (l == 0 ? 0 : pre[l - 1]);
        int mx = t.query(l + 1, r);

        cout << abs(min(0ll, mx - temp)) << "\n";
    }
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