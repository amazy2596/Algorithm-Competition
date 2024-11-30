#include <bits/stdc++.h>
#define int long long
using namespace std;

class SegmentTree
{
    public:
        vector<int> data, tree, lazy, has_lazy;
        vector<pair<int, int>> ranges;
        int n;

        SegmentTree(vector<int> &input)
        {
            n = input.size();
            data = input;
            tree.resize(4 * n);
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

                tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
            }
        }

        void apply_lazy(int node, int start, int end)
        {
            if (has_lazy[node])
            {
                tree[node] = (end - start + 1) * lazy[node];
                if (start != end)
                {
                    int mid = (start + end) / 2;

                    lazy[node * 2 + 1] = lazy[node];
                    has_lazy[node * 2 + 1] = 1;

                    lazy[node * 2 + 2] = lazy[node];
                    has_lazy[node * 2 + 2] = 1;
                }

                lazy[node] = 0;
                has_lazy[node] = 0;
            }
        }

        int query(int node, int start, int end, int l, int r)
        {
            apply_lazy(node, start, end);
            if (l > end || r < start)
                return 0;
            if (l <= start && end <= r)
                return tree[node];

            int mid = (start + end) / 2;
            int left = query(node * 2 + 1, start, mid, l, r);
            int right = query(node * 2 + 2, mid + 1, end, l , r);

            return left + right;
        }

        void update(int node, int start, int end, int l, int r, int val)
        {
            apply_lazy(node, start, end);
            if (l > end || r < start)
                return;
            if (l <= start && end <= r)
            {
                tree[node] = (end - start + 1) * val;
                lazy[node] = val;
                has_lazy[node] = 1;
                return;
            }

            int mid = (start + end) / 2;
            update(node * 2 + 1, start, mid, l, r, val);
            update(node * 2 + 2, mid + 1, end, l, r, val);

            tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
        }

        int query(int l, int r)
        {
            return query(0, 0, n - 1, l, r);
        }

        void update(int l, int r, int val)
        {
            update(0, 0, n - 1, l, r, val);
        }
};

void solve()
{
    vector<int> a = {1, 2, 3};
    SegmentTree tree(a);

    cout << tree.query(0, 3) << "\n";

    tree.update(2, 4, 5);

    cout << tree.query(0, 3) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}