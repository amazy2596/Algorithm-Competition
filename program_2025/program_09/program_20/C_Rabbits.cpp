// Problem: C. Rabbits
// URL: https://codeforces.com/contest/2147/problem/C
// Author: amazy
// Date: 2025-09-20 22:52:12

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
    string s;
    cin >> s;
    s = " " + s;

    int cnt = 0;
    vector<vector<int>> dp(n + 1, {0, 0});
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
        {
            cnt++;
            if (i == 1) dp[i][0] = 1;
            if (i - 1 >= 0 && s[i - 1] == '0')
                dp[i][0] = max({dp[i][0], dp[i - 1][0] + 1, dp[i - 1][1] + 1});
            if (i - 2 >= 0 && s[i - 2] == '0' && s[i - 1] == '1')
                dp[i][0] = max({dp[i][0], dp[i - 2][1] + 2});
            if (i + 1 <= n && s[i + 1] == '0')
                dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;

            dp[i][1] = max({dp[i][1], dp[i - 1][0], dp[i - 1][1]});
            if (i == n) dp[i][1]++;
        }
        else 
            dp[i] = dp[i - 1];
    }

    if (max(dp[n][0], dp[n][1]) == cnt)
        cout << "YES\n";
    else 
        cout << "NO\n";
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