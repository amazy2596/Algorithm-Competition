#include <bits/stdc++.h>
#define int long long
using namespace std;

class SegmentTree
{
    private:
        int n;
        vector<int> tree, data;

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

        int queryRange(int node, int start, int end, int l, int r)
        {
            if (l > end || r < start)
                return 0;
            if (l <= start && end <= r)
                return tree[node];

            int mid = (start + end) / 2;
            int left = queryRange(2 * node + 1, start, mid, l, r);
            int right = queryRange(2 * node + 2, mid + 1, end, l, r);

            return left + right;
        }

    public:
        SegmentTree(vector<int>& input)
        {
            data = input;
            n = data.size();
            tree.resize(4 * n, 0);
            build(0, 0, n - 1);
        }

        int queryRange(int l, int r)
        {
            return queryRange(0, 0, n - 1, l, r);
        }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];

    SegmentTree tree(a);
    
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        int circle_l = (l - 1) / n, circle_r = (r - 1) / n;
        int remain_l = (l % n + (circle_l - 1)) % n;
        int remain_r = (r % n + (circle_r - 1)) % n;
        int idx_l = circle_l;
        int idx_r = circle_r;
        if (l <= n)
        {
            if (r <= n)
            {
                ans += tree.queryRange(l - 1, r - 1);
                cout << ans << "\n";
                continue;
            }
            ans += tree.queryRange(l - 1, n - 1);
            ans += (circle_r - circle_l - 1) * sum;
            if (remain_r >= idx_r)
                ans += tree.queryRange(circle_r, remain_r);
            else 
                ans += tree.queryRange(circle_r, n - 1) + tree.queryRange(0, remain_r);
            cout << ans << "\n";
            continue;
        }
        if (circle_l == circle_r)
        {
            if (remain_r < idx_r && remain_l >= idx_l)
                ans += tree.queryRange(remain_l, n - 1) + tree.queryRange(0, remain_r);
            else
                ans += tree.queryRange(remain_l, remain_r);
        }
        else
        {
            ans += (circle_r - circle_l - 1) * sum;
            if (remain_l >= idx_l)
            {
                ans += tree.queryRange(remain_l, n - 1) + tree.queryRange(0, circle_l - 1);
                if (remain_r >= idx_r)
                    ans += tree.queryRange(circle_r, remain_r);
                else 
                    ans += tree.queryRange(circle_r, n - 1) + tree.queryRange(0, remain_r);
            }
            else
            {
                ans += tree.queryRange(remain_l, circle_l - 1);
                if (remain_r >= idx_r)
                    ans += tree.queryRange(circle_r, remain_r);
                else 
                    ans += tree.queryRange(circle_r, n - 1) + tree.queryRange(0, remain_r);
            }
        }
        cout << ans << "\n";
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