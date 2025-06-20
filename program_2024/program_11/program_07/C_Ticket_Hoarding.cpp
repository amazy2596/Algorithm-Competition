#include <bits/stdc++.h>
#define int long long
using namespace std;

class segmentTree
{
    public:
        int n;
        vector<int> data, tree, lazy;
        vector<bool> has_lazy;

        segmentTree(vector<int> &a)
        {
            data = a;
            n = data.size();
            tree.resize(4 * n);
            lazy.resize(4 * n);
            has_lazy.resize(4 * n);
        }

        void build(int node, int start, int end)
        {
            if (start == end)
                tree[node] = data[node];
            else
            {
                int mid = (start + end) / 2;

                build(2 * node + 1, start, mid);
                build(2 * node + 2, mid + 1, end);

                tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
            }
        }

        void push_down(int node, int start, int end)
        {
            if (has_lazy[node])
            {
                int mid = (start + end) / 2;

                tree[2 * node + 1] = lazy[node] * (mid - start + 1);
                lazy[2 * node + 1] = lazy[node];
                has_lazy[2 * node + 1] = true;

                tree[2 * node + 2] = lazy[node] * (end - mid);
                lazy[2 * node + 2] = lazy[node];
                has_lazy[2 * node + 2] = true;

                lazy[node] = 0;
                has_lazy[node] = false;
            }
        }

        void update(int node, int start, int end, int l, int r, int value)
        {
            if (l > end || r < start)
                return;

            if (l <= start && end <= r)
            {
                tree[node] = value * (end - start + 1);
                lazy[node] = value;
                has_lazy[node] = true;
                return;
            }

            push_down(node, start, end);

            int mid = (start + end) / 2;
            update(2 * node + 1, start, mid, l, r, value);
            update(2 * node + 2, mid + 1, end, l, r, value);

            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }

        int query(int node, int start, int end, int l, int r)
        {
            if (l > end || r < start)
                return 0;
            
            if (l <= start && end <= r)
                return tree[node];

            push_down(node, start, end);

            int mid = (start + end) / 2;

            int left = query(2 * node + 1, start, mid, l, r);
            int right = query(2 * node + 2, mid + 1, end, l, r);

            return left + right;
        }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int cnt = k / m;
    int ans = (m * (k - m) * cnt + (k - cnt * m) * (cnt * m)) / 2;
    for (int i = 0; i < n; i++)
    {
        if (k >= m)
        {
            ans += a[i] * m;
            k -= m;
        }
        else
        {
            ans += a[i] * k;
            break;
        }
    }
    cout << ans << "\n";
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