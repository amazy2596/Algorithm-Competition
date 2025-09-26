// Problem: 构造序列
// URL: https://ac.nowcoder.com/acm/contest/117762/E
// Author: amazy
// Date: 2025-09-26 19:56:42

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

i64 fast_pow(i64 a, i64 b) 
{
    i64 res = 1;
    a %= mod;
    while (b) 
    {
        if (b & 1)
            res = (1LL * res * a) % mod;

        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}

i64 inv(i64 x) 
{
    return fast_pow(x, mod - 2);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int cnt = 1;
    while ((cnt + 1) * ((cnt + 1) + 1) / 2 <= n)
        cnt++;

    i64 ans = 0;
    vector<array<i64, 2>> dp(n + 1, {0, 0});
    dp[0][0] = 1;
    int op = 1;
    for (int k = 1; k <= cnt; k++)
    {
        dp[0][op] = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i][op] = (dp[i - 1][op ^ 1] + (i - k >= 0 ? dp[i - k][op] : 0)) % mod;
        }
        i64 cur = dp[n - k * (k - 1) / 2][op] % mod;
        i64 tmp = m * fast_pow(m - 1, k - 1) % mod;
        ans = (ans + cur * tmp) % mod;
        op ^= 1;
    }

    cout << ans % mod << "\n";
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