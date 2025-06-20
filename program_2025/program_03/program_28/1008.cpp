#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector a(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            cin >> a[i][j];
    
    vector dp(n + 1, vector<int>(k + 1, 0));
    int last_mx = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int k = 1; k <= j; k++)
            {
                dp[i][j] = max({dp[i][j], dp[i - 1][j] + a[i][j], dp[i - 1][k] + a[i][j]});
            }
            // dp[i][j] = max({dp[i][j], dp[i - 1][j] + a[i][j], dp[i - 1][j - 1] + a[i][j]});
        }
    }

    cout << *max_element(dp[n].begin(), dp[n].end()) << "\n";
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