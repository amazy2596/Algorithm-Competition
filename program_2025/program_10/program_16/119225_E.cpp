// Problem: 二小姐取数
// URL: https://ac.nowcoder.com/acm/contest/119225/E
// Author: amazy
// Date: 2025-10-16 11:17:45

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
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    const int M = 495;
    vector<vector<i64>> dp(2 * n + 5, vector<i64>(M, 0));
    dp[n][0] = 1;
    int hi = n, lo = n;
    for (int i = 1; i <= n; i++)
    {
        for (int d = hi; d >= lo; d--)
        {
            for (int r = 0; r < M; r++)
            {
                int val = (r + a[i]) % M;
                dp[d + 1][val] += dp[d][r];
                dp[d + 1][val] %= mod;
            }
        }
        hi++;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int d = lo; d <= hi; d++)
        {
            for (int r = 0; r < M; r++)
            {
                int val = (r + b[i]) % M;
                dp[d - 1][val] += dp[d][r];
                dp[d - 1][val] %= mod;
            }
        }
        lo--;
    }

    for (int r = 0; r < M; r++)
    {
        i64 ans = 0;
        for (int d = n; d <= 2 * n; d++)
        {
            ans += dp[d][r];
            ans %= mod;
        }
        cout << ans << " ";
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}