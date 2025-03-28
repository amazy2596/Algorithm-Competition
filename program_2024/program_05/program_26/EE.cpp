#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int a, h;
    cin >> a >> h;
    int mx = max(a, h) + 10;
    vector<vector<int>> dp(mx + 1, vector<int>(mx + 1, INT32_MAX));
    dp[1][0] = 0;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 0; j <= mx; j++)
        {
            if (dp[i][j] == INT32_MAX)
                continue;
            int have_need = ceil(1.0 * h / i);
            int damage = max(0 , a - j);
            int tot = damage * (have_need - 1);
            if (i + 1 <= h)
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + tot);
            if (j + 1 <= mx)   
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + tot);
        }
    }
    int ans = INT32_MAX;
    for (int j = 0; j <= mx; j++)
        ans = min(ans, dp[h][j]);
    for (int i = 0; i <= mx; i++)
        ans = min(ans, dp[i][a]);
    cout << ans;
    return 0;
}