#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n + 1));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            a[i][j] = ch == 'A';
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(3, -1));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int cnt = 0;
            if (dp[i][j] != -1)
            {
                if (j == 0)
                {
                    // 1
                    if (i + 3 <= n)
                    {
                        cnt = (a[0][i + 1] + a[0][i + 2] + a[0][i + 3] >= 2) + (a[1][i + 1] + a[1][i + 2] + a[1][i + 3] >= 2);
                        dp[i + 3][0] = max(dp[i + 3][0], dp[i][j] + cnt);
                    }

                    // 2
                    if (i + 2 <= n)
                    {
                        cnt = (a[0][i + 1] + a[0][i + 2] + a[1][i + 1] >= 2);
                        dp[i + 1][1] = max(dp[i + 1][1], dp[i][j] + cnt);
                    }

                    // 3
                    if (i + 2 <= n)
                    {
                        cnt = (a[0][i + 1] + a[1][i + 1] + a[1][i + 2] >= 2);
                        dp[i + 1][2] = max(dp[i + 1][2], dp[i][j] + cnt);
                    }

                }
                else if (j == 1)
                {
                    if (i + 2 <= n)
                    {
                        cnt = (a[1][i + 1] + a[1][i + 2] + a[0][i + 2] >= 2);
                        dp[i + 2][0] = max(dp[i + 2][0], dp[i][j] + cnt);
                    }
                    if (i + 4 <= n)
                    {
                        cnt = (a[0][i + 2] + a[0][i + 3] + a[0][i + 4] >= 2) + (a[1][i + 1] + a[1][i + 2] + a[1][i + 3] >= 2);
                        dp[i + 3][1] = max(dp[i + 3][1], dp[i][j] + cnt);
                    }
                }
                else if (j == 2)
                {
                    if (i + 2 <= n)
                    {
                        cnt = (a[0][i + 1] + a[0][i + 2] + a[1][i + 2] >= 2);
                        dp[i + 2][0] = max(dp[i + 2][0], dp[i][j] + cnt);
                    }
                    if (i + 4 <= n)
                    {
                        cnt = (a[0][i + 1] + a[0][i + 2] + a[0][i + 3] >= 2) + (a[1][i + 2] + a[1][i + 3] + a[1][i + 4] >= 2);
                        dp[i + 3][2] = max(dp[i + 3][2], dp[i][j] + cnt);
                    }
                }
            }
        }
    }
    cout << dp[n][0] << "\n";
    
}

signed main()
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