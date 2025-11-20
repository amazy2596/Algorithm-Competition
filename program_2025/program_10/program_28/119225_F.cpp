// Problem: 二小姐的区间查询
// URL: https://ac.nowcoder.com/acm/contest/119225/F
// Author: amazy
// Date: 2025-10-28 15:03:29

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

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

// 1 495
// 3 165
// 5 99
// 9 55
// 11 45
// 15 33

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<Fenwick> fw(16, Fenwick(n + 1));

    auto get = [&](int x)
    {
        int mask = 0;
        if (x % 3 == 0) mask |= (1 << 0);
        if (x % 9 == 0) mask |= (1 << 1);
        if (x % 5 == 0) mask |= (1 << 2);
        if (x % 11 == 0) mask |= (1 << 3);
        return mask;
    };

    for (int i = 1; i <= n; i++)
    {
        int mask = get(a[i]);
        fw[mask].update(i, 1);
    }

    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y;
            cin >> x >> y;
            int omask = get(a[x]);
            fw[omask].update(x, -1);
            int nmask = get(y);
            fw[nmask].update(x, 1);
            a[x] = y;
        }
        else if (op == 2)
        {
            int l, r;
            cin >> l >> r;
            i64 ans = 0;
            for (int i = 0; i < 16; i++)
            {
                for (int j = i; j < 16; j++)
                {
                    int mask = 0;
                    if ((i >> 3 & 1) | (j >> 3 & 1)) mask |= (1 << 2);
                    if ((i >> 2 & 1) | (j >> 2 & 1)) mask |= (1 << 1);
                    if ((i >> 1 & 1) | (j >> 1 & 1) | ((i & 1) & (j & 1))) mask |= (1 << 0);
                    if (mask != 7) continue;

                    i64 x = fw[i].query(l, r), y = fw[j].query(l, r);
                    if (i == j) ans += x * (x - 1) / 2;
                    else ans += fw[i].query(l, r) * fw[j].query(l, r);
                }
            }

            cout << ans << "\n";
        }
    }
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