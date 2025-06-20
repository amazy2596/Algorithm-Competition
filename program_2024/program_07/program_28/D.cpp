#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    const int N = 1e5 + 5;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), dp(n, vector<int>(N));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int target;
    cin >> target;
    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < m; j++)
                dp[i][a[i][j]] = 1;
            continue;
        }
        for (int j = 0; j <= N; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (j - a[i][k] >= 0)
                    dp[i][j] += dp[i - 1][j - a[i][k]];
            }
        }
    }
    for (int j = 0; j <= N; j++)
        if (dp[n - 1][j])
            ans = min(ans, abs(target - j));
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    solve();
    return 0;
}