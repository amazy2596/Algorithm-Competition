// Problem: L3-3 领头
// URL: https://ac.nowcoder.com/acm/contest/130247/O
// Author: amazy
// Date: 2026-03-14 16:34:12

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

const int mod = 998244353;
struct Fenwick
{
    int n;
    vector<int> a;

    Fenwick() {}
    Fenwick(int _n) : n(_n), a(_n + 1) {}

    int lowbit(int x)
    {
        return x & -x;
    }

    void update(int x, int k)
    {
        while (x >= 1 && x <= n)
        {
            a[x] += k;
            a[x] %= mod;
            x += lowbit(x);
        }
    }

    int pre(int r)
    {
        int res = 0;   

        while (r > 0)
        {
            res += a[r];
            res %= mod;
            r -= lowbit(r);
        }

        return res;
    }

    int query(int l, int r)
    {
        return pre(r) - pre(l - 1);
    }

    int kth(int k)
    {
        int ans = 0;
        for (int p = __lg(n); p >= 0; p--)
        {
            int step = 1ll << p;
            if (ans + step <= n && a[ans + step] < k)
            {
                k -= a[ans + step];
                ans += step;
            }
        }

        return ans + 1;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> tmp = a;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    tmp.insert(tmp.begin(), 0);
    int m = tmp.size();
    map<int, int> id;
    for (int i = 1; i < tmp.size(); i++) id[tmp[i]] = i;

    Fenwick fw1(m + 1), fw2(m + 1);
    vector<i64> l(n + 1), r(n + 1);
    for (int i = 0; i < n; i++) l[i] = 1 + fw1.query(0, id[a[i]] - 1), fw1.update(id[a[i]], l[i]);
    for (int i = n - 1; i >= 0; i--) r[i] = 1 + fw2.query(0, id[a[i]] - 1), fw2.update(id[a[i]], r[i]);
    i64 ans = 0;
    for (int i = 0; i < n; i++) ans = (ans + l[i] * r[i]) % mod;
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}