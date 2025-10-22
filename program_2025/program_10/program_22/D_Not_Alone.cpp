// Problem: D. Not Alone
// URL: https://codeforces.com/contest/2153/problem/D
// Author: amazy
// Date: 2025-10-22 11:33:42

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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<array<int, 2>> dp(n + 1, {inf, inf});
    dp[1][0] = dp[1][1] = 0;
    dp[2][0] = dp[2][1] = abs(a[1] - a[2]);
    for (int i = 3; i <= n; i++)
    {
        dp[i][0] = min({dp[i][0], dp[i - 1][0] + abs(a[i - 1] - a[i]), dp[i - 1][1] + abs(a[i - 1] - a[i])});
        
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