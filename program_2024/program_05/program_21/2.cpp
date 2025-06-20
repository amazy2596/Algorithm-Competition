#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT32_MIN));
    // dp[0][0] = 0;
    // int ans = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         if (j >= v[i])
    //             dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
    //         else
    //             dp[i][j] = dp[i - 1][j];
    //         ans = max(ans, dp[i][j]);
    //     }
    // }
    // cout << ans << "\n";
    vector<int> dp(m + 1, INT32_MIN);
    dp[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]), ans = max(ans, dp[j]);
    cout << ans << "\n";
    return 0;
}