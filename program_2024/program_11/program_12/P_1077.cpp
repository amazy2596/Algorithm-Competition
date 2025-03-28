#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e6 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    // dp[0][0] = 1;
    vector<int> dp(m + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 1; k <= min(j, a[i]); k++)
            {
                dp[j] = (dp[j] + dp[j - k]) % mod;
            }
        }
    }
    cout << dp[m] % mod << "\n";
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