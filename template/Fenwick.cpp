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
            return query(r) - query(l - 1);
        }
};

void solve()
{
    
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