#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

class SegmentTree
{
    public:
        vector<int> tree, data;
        int n;

        SegmentTree(vector<int> &input)
        {
            data = input;
            n = data.size();
            tree.resize(4 * n, 0);
            build(0, 0, n - 1);
        }

        void build(int node, int start, int end)
        {
            if (start == end)
                tree[node] = data[start];
            else
            {
                int mid = start + end >> 1;
                build(node * 2 + 1, start, mid);
                build(node * 2 + 2, mid + 1, end);

                tree[node] = __gcd(tree[node * 2 + 1], tree[node * 2 + 2]);
            }
        }

        int query(int node, int start, int end, int l, int r)
        {
            if (l > end || r < start)
                return 0;

            if (l <= start && end <= r)
                return tree[node];

            int mid = start + end >> 1;
            int left = query(node * 2 + 1, start, mid, l, r);
            int right = query(node * 2 + 2, mid + 1, end, l, r);

            return __gcd(left, right);
        }
        
        int query(int l, int r)
        {
            return query(0, 0, n - 1, l, r);
        }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i > 1)
            b[i - 1] = abs(a[i] - a[i - 1]);
    }
    SegmentTree tree(b);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (l == r)
            cout << 0 << " ";
        else
            cout << tree.query(l, r - 1) << " ";
    }
    cout << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}