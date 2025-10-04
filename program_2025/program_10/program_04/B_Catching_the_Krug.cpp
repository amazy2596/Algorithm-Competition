// Problem: B. Catching the Krug
// URL: https://codeforces.com/contest/2152/problem/B
// Author: amazy
// Date: 2025-10-04 15:17:26

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
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    int ans = 0;
    if (x1 < x2)
        ans = max(ans, x2);
    else if (x1 > x2)
        ans = max(ans, n - x2);

    if (y1 < y2)
        ans = max(ans, y2);
    else if (y1 > y2)
        ans = max(ans, n - y2);

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