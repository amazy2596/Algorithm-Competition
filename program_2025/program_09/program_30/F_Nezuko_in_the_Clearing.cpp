// Problem: F. Nezuko in the Clearing
// URL: https://codeforces.com/contest/2149/problem/F
// Author: amazy
// Date: 2025-09-30 18:41:13

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
    i64 h, d;
    cin >> h >> d;

    auto cost = [&](i64 n)
    {
        return n * (n + 1) / 2;
    };

    auto check = [&](i64 x)
    {
        int k = x + 1;
        int q = d / k;
        int rem = d % k;

        return h + x > rem * cost(q + 1) + (k - rem) * cost(q);
    };

    i64 l = 0, r = d;
    while (l < r)
    {
        i64 mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else 
            l = mid + 1;
    }

    cout << d + l << "\n";
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