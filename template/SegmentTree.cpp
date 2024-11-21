#include <bits/stdc++.h>
#define int long long
using namespace std;

class SegmentTree
{
    private:
        vector<int> tree, lazy, data;
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

                tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // 区间和
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

        void update_range(int node, int start, int end, int l, int r, int value)
        {
            apply_lazy(node, start, end);

            if (l > end || r < start)
                return ;

            if (l <= start && end <= r)
            {
                tree[node] += (end - start + 1) * value;
                if (start != end)
                {
                    lazy[2 * node + 1] += value;
                    lazy[2 * node + 2] += value;
                }

                return;
            }

            int mid = (start + end) / 2;
            
            update_range(2 * node + 1, start, mid, l, r, value);
            update_range(2 * node + 2, mid + 1, end, l, r, value);

            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // 区间和
        }

        int query_range(int node, int start, int end, int l, int r)
        {
            apply_lazy(node, start, end);

            if (start > r || end < l)
                return 0;

            if (start >= l && end <= r)
                return tree[node];
            
            int mid = (start + end) / 2;
            int left = query_range(2 * node + 1, start, mid, l, r);
            int right = query_range(2 * node + 2, mid + 1, end, l, r);

            return left + right; // 区间和
        }

    public:

        SegmentTree(vector<int>& input)
        {
            data = input;
            n = input.size();
            tree.resize(4 * n, 0);
            lazy.resize(4 * n, 0);
            build(0, 0, n - 1);
        }

        void update_range(int l, int r, int value)
        {
            update_range(0, 0, n - 1, l, r, value);
        }

        int query_range(int l, int r)
        {
            return query_range(0, 0, n - 1, l, r);
        }

};

void solve()
{
    vector<int> a = {1, 2, 3};
    SegmentTree tree(a);

    cout << tree.query_range(0, 3) << "\n";

    tree.update_range(2, 4, 5);

    cout << tree.query_range(0, 3) << "\n";
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