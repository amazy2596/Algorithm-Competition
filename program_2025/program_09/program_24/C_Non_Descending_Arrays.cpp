// Problem: C. Non-Descending Arrays
// URL: https://codeforces.com/contest/2144/problem/C
// Author: amazy
// Date: 2025-09-24 18:08:31

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 998244353;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    vector<array<i64, 2>> dp(n + 1, {0, 0});
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] >= a[i - 1] && b[i] >= b[i - 1])
        {
            dp[i][0] += dp[i - 1][0];
            dp[i][1] += dp[i - 1][1];
        }
        if (a[i] >= b[i - 1] && b[i] >= a[i - 1])
        {
            dp[i][0] += dp[i - 1][1];
            dp[i][1] += dp[i - 1][0];
        }

        dp[i][0] %= mod;
        dp[i][1] % mod;
    }

    cout << (dp[n][0] + dp[n][1]) % mod << "\n";
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