#include <bits/stdc++.h>
#define int long long
using namespace std;

class SegmentTree
{
    public:
        int n;
        vector<int> tree, data, lazy;
        vector<int> has_lazy;
        vector<pair<int, int>> ranges;

        SegmentTree(vector<int> &input)
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
            if (r < start || l > end)
                return;
            if (l <= start && end <= r)
            {
                tree[node] = val;
                lazy[node] = val;
                has_lazy[node] = 1;
                return;
            }

            apply_lazy(node, start, end);

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(m + 1, n);
    SegmentTree tree(h);
    vector<pair<pair<int, int>, pair<int, int>>> line(k);
    for (int i = 0; i < k; i++)
    {
        int r, c, l;
        cin >> r >> c >> l;
        line[i] = {{r, i}, {c, c + l - 1}};
    }
    sort(line.begin(), line.end());

    vector<int> ans(k);
    for (int i = k - 1; i >= 0; i--)
    {
        int idx = line[i].first.second;
        int l = line[i].second.first, r = line[i].second.second;
        int res = tree.query(l, r);
        ans[idx] = res;
        tree.update(l, r, res - 1);
    }
    for (int i = 0; i < k; i++)
        cout << ans[i] << "\n";
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