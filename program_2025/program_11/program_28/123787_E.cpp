// Problem: 小红的gcd
// URL: https://ac.nowcoder.com/acm/contest/123787/E
// Author: amazy
// Date: 2025-11-28 20:01:17

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<string> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i];
        g[i] = " " + g[i];
    }

    int k = (2 * n - 1) / 3;
    i64 ans = 0;
    vector<int> p = {0, 1, 2};
    vector<char> ch = {'g', 'c', 'd'};
    do
    {
        string tar = " " + string(k, ch[p[0]]) + string(k, ch[p[1]]) + string(k, ch[p[2]]);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (g[i][j] == tar[i + j - 1])
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }

        ans = (ans + dp[n][n]) % mod;
    } while (next_permutation(p.begin(), p.end()));

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