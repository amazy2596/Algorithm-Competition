// Problem: D1. Inversion Graph Coloring (Easy Version)
// URL: https://codeforces.com/contest/2143/problem/D1
// Author: amazy
// Date: 2025-09-25 11:05:14

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
    vector<i64> a;

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
        i64 res = 0;   

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

int pos(int x)
{
    return x + 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v[i] = {x, i};
    }
    sort(v.begin() + 1, v.end());
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        a[v[i].second] = i;

    // vector<vector<i64>> dp(n + 1, vector<i64>(n + 1)), ndp(n + 1, vector<i64>(n + 1));
    // dp[0][0] = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     int x = a[i];
    //     ndp = dp;

    //     for (int j = 0; j <= n; j++)
    //     {
    //         for (int k = 0; k <= j; k++)
    //         {
    //             if (x > j)
    //                 ndp[x][k] = (ndp[x][k] + dp[j][k]) % mod;
    //             if (j > x && x > k)
    //                 ndp[j][x] = (ndp[j][x] + dp[j][k]) % mod;
    //         }
    //     }
    //     dp.swap(ndp);
    // }
    // 
    // i64 ans = 0;
    // for (int i = 0; i <= n; i++)
    // {
        // for (int j = 0; j <= n; j++)
        // {
            // ans = (ans + dp[i][j]) % mod;
        // }
    // }

    // cout << ans << "\n";

    vector<Fenwick> row(n + 2, Fenwick(n + 2)), col(n + 2, Fenwick(n + 2));
    row[0].update(pos(0), 1);
    col[0].update(pos(0), 1);
    i64 ans = 1;

    for (int i = 1; i <= n; i++)
    {
        int x = a[i];

        for (int k = 0; k < x; k++)
        {
            i64 add = row[k].pre(x);
            row[k].update(pos(x), add);
            col[x].update(pos(k), add);
            ans = (ans + add) % mod;
        }

        for (int j = x + 1; j <= n; j++)
        {
            i64 add = col[j].pre(x);
            row[x].update(pos(j), add);
            col[j].update(pos(x), add);
            ans = (ans + add) % mod;
        }
    }

    cout << ans << "\n";
}

int main()
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