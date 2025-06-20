#include <bits/stdc++.h>
#define int long long
using namespace std;

class SegmentTree
{
    private:
        vector<int> tree, data, lazy;
        int n;

        void build(int node, int start, int end)
        {
            if (start == end)
                tree[node] = data[start];
            else 
            {
                int mid = (start + end) / 2;
                build(2 * node + 1, start, mid);
                build(2 * node + 2, mid + 1, end);
                tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
            }
        }

        void apply_lazy(int node, int start, int end)
        {
            if (lazy[node] != 0)
            {
                tree[node] += (end - start + 1) * lazy[node];

                if (start != end)
                {
                    lazy[2 * node + 1] += lazy[node];
                    lazy[2 * node + 2] += lazy[node];
                }

                lazy[node] = 0;
            }
        }

        void update_range(int node, int start, int end, int l, int r, int val)
        {
            apply_lazy(node, start, end);

            if (l > end || r < start)
                return;

            if (l <= start && end <= r)
            {
                tree[node] += (end - start + 1) * val;

                if (start != end)
                {
                    lazy[2 * node + 1] += val;
                    lazy[2 * node + 2] += val;
                }

                return;
            }

            int mid = (start + end) / 2;

            update_range(2 * node + 1, start, mid, l, r, val);
            update_range(2 * node + 2, mid + 1, end, l, r, val);

            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }

        int query_range(int node, int start, int end, int l, int r)
        {
            apply_lazy(node, start, end);

            if (l > end || r < start)
                return 0;

            if (l <= start && end <= r)
                return tree[node];
            
            int mid = (start + end) / 2;
            int left = query_range(2 * node + 1, start, mid, l, r);
            int right = query_range(2 * node + 2, mid + 1, end, l, r);

            return left + right;
        }

    public:

        SegmentTree(vector<int>& input)
        {
            data = input;
            n = data.size();
            tree.resize(4 * n);
            lazy.resize(4 * n);
            build(0, 0, n - 1);
        }

        void update_range(int l, int r, int val)
        {
            update_range(0, 0, n - 1, l , r, val);
        }

        int query_range(int l, int r)
        {
            return query_range(0, 0, n - 1, l, r);
        }

};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegmentTree tree(a);

    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            x--, y--;
            tree.update_range(x, y, k);
        }
        else 
        {
            int x, y;
            cin >> x >> y;
            x--, y--;
            cout << tree.query_range(x, y) << "\n";
        }
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