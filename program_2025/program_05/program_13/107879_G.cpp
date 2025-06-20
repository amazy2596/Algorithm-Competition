#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 2e5 + 5;

struct Fenwick
{
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
        if (l > r)
            return 0;
        return query(r) - query(l - 1);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    

    int q;
    cin >> q;
    int v;
    cin >> v;

    Fenwick f1(N), f2(N);
    vector<int> pre(n);
    for (int i = 0; i < n; i++)
    {
        pre[i] = f1.query(v + 1, N - 1);
        f1.update(a[i], 1);
    }
    int ans = 1e9;
    
    for (int i = n - 1; i >= 0; i--)
    {
        ans = min(ans, pre[i] + f2.query(a[i] + 1, N - 1));
        f2.update(a[i], 1);
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