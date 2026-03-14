// Problem: Block Array
// URL: https://ac.nowcoder.com/acm/contest/125083/E
// Author: amazy
// Date: 2026-03-09 14:47:12

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    i64 ans = 0;
    vector<i64> dp(n + 1), len(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || a[i] == a[i - 1])
            len[i] = len[i - 1] + 1;
        else
            len[i] = 1;

        if (len[i] >= a[i])
            dp[i] = dp[i - a[i]] + 1;
        else 
            dp[i] = 0;
        ans += dp[i];
    }

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