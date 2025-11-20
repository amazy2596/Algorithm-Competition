// Problem: G. Mukhammadali and the Smooth Array
// URL: https://codeforces.com/contest/2167/problem/G
// Author: amazy
// Date: 2025-10-28 22:57:30

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
    vector<i64> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> c[i];

    vector<i64> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = c[i];
        for (int j = i - 1; j >= 1; j--)
        {
            if (a[j] <= a[i])
            {
                dp[i] = max(dp[i], c[i] + dp[j]);
            }
        }
    }

    i64 ans = accumulate(c.begin() + 1, c.end(), 0LL) - *max_element(dp.begin() + 1, dp.end());

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