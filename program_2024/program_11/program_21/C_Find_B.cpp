#include <bits/stdc++.h>
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
            while (1 <= x && x <= n)
            {
                a[x] += k;
                x += lowbit(x);
            }
        }

        int query(int x)
        {
            int res = 0;
            while (x >= 1)
            {
                res += a[x];
                x -= lowbit(x);
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
    vector<int> c(n + 1), pre(n + 1);
    Fenwick f(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        pre[i] = pre[i - 1] + c[i];
        if (c[i] == 1)
            f.update(i, 1);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int cnt = f.query(l, r);
        int mn = cnt * 2 + (r - l + 1 - cnt);
        if (mn > pre[r] - pre[l - 1] || l == r)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
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