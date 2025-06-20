#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector dp(n + 1, vector<int>(k + 1, -1e18l));
    dp[0][0] = 0;
    int ans = -1e18l;
    for (int i = 0; i <= n; i++)
    {
        for (int len = 1; len <= 6 && i + len <= n; len++)
        {
            for (int j = 0; j + 1 <= k; j++)
            {
                if (dp[i][j] != -1e18l)
                    dp[i + len][j + 1] = max(dp[i + len][j + 1], dp[i][j] + a[i + len]);
            }
        }

        ans = max(ans, dp[i][k]);
    }

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}