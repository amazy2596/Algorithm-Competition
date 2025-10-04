// Problem: D. Division Versus Addition
// URL: https://codeforces.com/contest/2152/problem/D
// Author: amazy
// Date: 2025-10-04 16:03:15

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



void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), pre(n + 1), cnt(n + 1);
    auto get = [&](int x)
    {
        int res = 0;
        while (x > 1)
        {
            x >>= 1;
            if (x > 1) x++;
            res++;
        }

        return res;
    };
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + get(a[i]);
        cnt[i] = cnt[i - 1] + (get(a[i]) < get(a[i] + 1));
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << pre[r] - pre[l - 1] + (cnt[r] - cnt[l - 1]) / 2 << "\n";
    }   
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