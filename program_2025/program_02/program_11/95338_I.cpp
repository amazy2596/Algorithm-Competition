#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

class Fenwick
{
    public:
        int n;
        vector<int> a;

        Fenwick(int size)
        {
            n = size;
            a.resize(n + 1, 0);
        }

        int lowbit(int x)
        {
            return x & -x;
        }

        void update(int x, int k)
        {
            while (x > 0 && x <= n)
            {
                a[x] += k;
                x += lowbit(x);
            }
        }

        int query(int r)
        {
            int res = 0;
            while (r > 0)
            {
                res += a[r];
                r -= lowbit(r);
            }
            return res;
        }

        int query(int l, int r)
        {
            return (query(r) - query(l - 1));
        }
};

struct node
{
    int l, r, c;
    int idx;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<pair<int, int>> p(n + 1);
    for (int i = 1; i <= n; i++)
        p[i] = {a[i], i};
    sort(p.begin() + 1, p.end());

    vector<node> q;
    for (int i = 1; i <= m; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
        q.push_back({l, r, a[c], i});
    }

    sort(q.begin(), q.end(), [&](node x, node y)
    {
        return x.c < y.c;
    });

    vector<int> ans(m + 1);
    Fenwick fw(n + 1);
    int j = 1;
    for (int i = 0; i < m; i++)
    {
        int tar = q[i].c;
        while (j < n && p[j].first < tar)
        {
            fw.update(p[j].second, 1);
            j++;
        }

        int temp = fw.query(q[i].l, q[i].r);
        ans[q[i].idx] = q[i].l + temp;
    }

    for (int i = 1; i <= m; i++)
        cout << ans[i] << "\n";
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