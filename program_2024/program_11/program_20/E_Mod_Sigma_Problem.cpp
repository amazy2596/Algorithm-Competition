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
            return query(r) - query(l - 1);
        }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = (pre[i - 1] + a[i]) % m;
    }
    Fenwick f(m);
    int ans = 0, s = 0;
    for (int r = 1; r <= n; r++)
    {
        ans += pre[r] * r - s + f.query(pre[r] + 1, m) * m;
        s += pre[r];
        f.update(pre[r], 1);
    }
    cout << ans << "\n";
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