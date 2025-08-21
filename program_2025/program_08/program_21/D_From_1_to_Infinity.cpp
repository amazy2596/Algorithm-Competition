// Problem: D. From 1 to Infinity
// URL: https://codeforces.com/contest/2132/problem/D
// Author: amazy
// Date: 2025-08-22 00:22:28

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
    i64 k;
    cin >> k;

    auto sum = [&](i64 n)
    {
        i64 res = 0;
        for (i64 p = 1; p <= n; p *= 10)
        {
            i64 high = n / (p * 10);
            i64 cur = (n / p) % 10;
            i64 low = n % p;

            res += high * 45 * p;
            res += (cur * (cur - 1) / 2) * p;
            res += cur * (low + 1);
        }

        return res;
    };

    auto get = [&](i64 n)
    {
        if (n == 0) return 0LL;

        i64 res = 0;
        i64 p = 1;
        int d = 1;
        while (p <= n)
        {
            i64 nxt = p * 10;
            i64 cnt = (n < nxt - 1 ? n : nxt - 1) - p + 1;
            i64 add = cnt * (i64)d;
            
            res += add;
            p = nxt;
            d++;
        }

        return res;
    };

    i64 l = 0, r = 1;
    while (get(r) <= k)
        r <<= 1;

    while (l < r)
    {
        i64 mid = l + r + 1 >> 1;
        if (get(mid) <= k)
            l = mid;
        else 
            r = mid - 1;
    }

    i64 remain = k - get(l);
    i64 ans = sum(l);
    string s = to_string(l + 1);
    for (int i = 0; i < remain && i < s.length(); i++)
        ans += (s[i] - '0');

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