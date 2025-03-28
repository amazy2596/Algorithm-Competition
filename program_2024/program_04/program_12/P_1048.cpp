#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t, m, ans = 0;
    cin >> t >> m;
    vector<int> a(m + 1), b(m + 1);
    vector<vector<int>> dp(m + 1, vector<int> (t + 1, INT32_MIN));
    for (int i = 1; i <= m; i++)
        cin >> a[i] >> b[i];
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= t; j++)
            dp[i][j] = dp[i - 1][j], ans = max(ans, dp[i][j]);
        for (int j = a[i]; j <= t; j++)
            dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + b[i]), ans = max(ans, dp[i][j]);
    }
    cout << ans;
    return 0;
}