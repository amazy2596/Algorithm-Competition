#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    const int mod = 1000000007;
    int n, m, kk;
    cin >> n >> m >> kk;
    string a, b;
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    vector<vector<vector<vector<int>>>> dp(2, vector<vector<vector<int>>>(m + 1, vector<vector<int>>(kk + 1, vector<int>(2))));
    dp[0][0][0][0] = 1;
    dp[1][0][0][0] = 1;
    for (int i = 1, val = 1; i <= n; i++, val ^= 1)
    {
        for (int j = 1; j <= m; j++)        
        {
            for (int k = 1; k <= kk; k++)
            {
                if (a[i] == b[j])
                {
                    dp[val][j][k][0] = (dp[val ^ 1][j][k][0] + dp[val ^ 1][j][k][1]) % mod;
                    dp[val][j][k][1] = (dp[val ^ 1][j - 1][k - 1][0] + dp[val ^ 1][j - 1][k - 1][1] + dp[val ^ 1][j - 1][k][1]) % mod;
                }
                else
                {
                    dp[val][j][k][0] = (dp[val ^ 1][j][k][0] + dp[val ^ 1][j][k][1]) % mod;
                    dp[val][j][k][1] = 0;
                }
            }
        }
    }
    cout << (dp[n & 1][m][kk][0] + dp[n & 1][m][kk][1]) % mod << "\n";
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