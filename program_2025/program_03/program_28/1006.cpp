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

        void update(int idx, int val)
        {
            while (idx > 0 && idx <= n)
            {
                a[idx] += val;
                idx += lowbit(idx);
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

        int query_ans(int l, int r)
        {
            return query(r) / 100 - query(l - 1) / 100;
        }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    Fenwick f(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        f.update(i, x);
    }
    int i = 1;
    int ans = 0;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int idx, val;
            cin >> idx >> val;
            int temp = f.query(idx, idx);
            f.update(idx, val - temp);

            // for (int i = 1; i <= n; i++)
                // cout << f.query(i, i) << " ";
            // cout << "\n";
        }
        else 
        {
            int l, r;
            cin >> l >> r;
            int res = f.query_ans(l, r);
            // cout << res << " ";
            ans ^= res * i;
            i++;
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