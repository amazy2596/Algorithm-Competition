// Problem: 小灯草序列
// URL: https://ac.nowcoder.com/acm/contest/124444/E
// Author: amazy
// Date: 2025-11-28 22:28:20

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

const int mod = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<array<int, 10>> dp(n + 1);
    for (int j = 0; j <= 9; j++) dp[1][j] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int x = 0; x <= 9; x++)
        {
            for (int y = 0; y <= 9; y++)
            {
                if (abs(x - y) <= k)
                {
                    dp[i][x] = (dp[i][x] + dp[i - 1][y]) % mod;
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= 9; j++) ans = (ans + dp[n][j]) % mod;
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}