// Problem: 小苯的数字变换
// URL: https://ac.nowcoder.com/acm/contest/117163/E
// Author: amazy
// Date: 2025-09-25 23:13:13

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
    string s;
    cin >> s;
    int n = s.length();
    s = " " + s;

    i64 ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(10));
    for (int i = 1; i <= n; i++)
    {
        int v = s[i] - '0';
        dp[i][v]++;
        for (int j = 0; j <= 9; j++)
        {
            if (j + v >= 10)
                dp[i][((j + v) % 10 + 1) % 10] += dp[i - 1][j];
            else 
                dp[i][j + v] += dp[i - 1][j];
        }
        for (int j = 1; j <= 9; j++)
            ans += 1LL * j * dp[i][j];
    }

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