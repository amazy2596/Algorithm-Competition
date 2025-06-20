#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            if (j == a[i])
                dp[i][j] = dp[i - 1][j] + 1;
            else if (j > a[i])
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
            else if (j < a[i])
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][m] << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}