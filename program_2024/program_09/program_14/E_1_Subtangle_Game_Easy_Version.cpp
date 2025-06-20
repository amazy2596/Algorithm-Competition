#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int l, n, m;
    cin >> l >> n >> m;
    vector<int> a(l);
    for (int i = 0; i < l; i++)
        cin >> a[i];
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    vector<vector<vector<bool>>> dp(l + 1, vector<vector<bool>>(n + 1, vector<bool>(m + 1)));
    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            for (int k = 0; k < l; k++)
            {
                if (i < n && dp[k][i + 1][j])
                {
                    dp[k][i][j] = 1;
                    continue;
                }
                if (j < m && dp[k][i][j + 1])
                {
                    dp[k][i][j] = 1;
                    continue;
                }

                if (g[i][j] == a[k])
                {
                    if (i < n && j < m)
                        dp[k][i][j] = !dp[k + 1][i + 1][j + 1];
                    else
                        dp[k][i][j] = 1;
                }
                else 
                    dp[k][i][j] = 0;
            }
        }
    }
    cout << (dp[0][1][1] ? "T\n" : "N\n");
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