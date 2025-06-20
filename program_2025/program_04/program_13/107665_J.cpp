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
            a.resize(n, 0);
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
            return query(r) - query(l - 1);
        }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector cnt(5005, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]].push_back(i);
    }

    vector<array<int, 4>> op(q);
    for (int i = 0; i < q; i++)
    {
        cin >> op[i][0] >> op[i][1] >> op[i][2];
        op[i][3] = i;
    }

    sort(op.begin(), op.end(), [&](array<int, 4> &a, array<int, 4> &b)
    {
        return a[2] < b[2];
    });

    Fenwick f(n + 1);
    int last = -1;
    vector<int> ans(q);
    for (auto [l, r, k, idx] : op)
    {
        if (last == -1)
        {
            for (int val = 1; val <= k; val++)
            {
                for (int j = 0; j < cnt[val].size(); j++)
                {
                    f.update(cnt[val][j], 1);
                }
            }
        }
        else 
        {
            for (int val = last + 1; val <= k; val++)
            {
                for (int j = 0; j < cnt[val].size(); j++)
                {
                    f.update(cnt[val][j], 1);
                }
            }
        }

        ans[idx] = f.query(l, r);
        last = k;
    }

    for (int i = 0; i < q; i++)
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