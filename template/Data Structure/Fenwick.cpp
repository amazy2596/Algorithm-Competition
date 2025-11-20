#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

// snippet-begin: Fenwick, 区间修改 + 区间查询
struct Fenwick
{
    int n;
    vector<int> a, b;

    Fenwick() {}
    Fenwick(int _n) : n(_n), a(_n + 1), b(_n + 1) {}

    int lowbit(int x)
    {
        return x & -x;
    }

    void modify(int x, int k, vector<int> &v)
    {
        while (x >= 1 && x <= n)
        {
            v[x] += k;
            x += lowbit(x);
        }
    }

    // (r + 1) * (a[1] + ... + a[r]) - (b[1] * 1 + ... + b[r] * r)
    void update(int l, int r, int k)
    {
        modify(l, k, a);
        modify(r + 1, -k, a);

        modify(l, k * l, b);
        modify(r + 1, -k * (r + 1), b);
    }

    int get(int x, vector<int> &v)
    {
        int res = 0;
        while (x > 0)
        {
            res += v[x];
            x -= lowbit(x);
        }

        return res;
    }

    int query(int l, int r)
    {
        if (l > r)
            return 0ll;

        int R = (r + 1) * get(r, a) - get(r, b);
        int L = l * get(l - 1, a) - get(l - 1, b);

        return R - L;
    }
};
// snippet-end

// snippet-begin: Fenwick, 单点修改 + 区间查询 + 第k小值
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
            x += lowbit(x);
        }
    }

    int pre(int r)
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
// snippet-end

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