// Problem: D. Chicken Jockey
// URL: https://codeforces.com/contest/2133/problem/D
// Author: amazy
// Date: 2025-08-24 23:04:43

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
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<i64> dp(n + 1, inf);
    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i <= n; i++)
        dp[i] = min(dp[i - 1] + a[i] - 1, dp[i - 2] + a[i - 1] + max(0, a[i] - (i - 1)));
    cout << dp[n] << "\n";
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