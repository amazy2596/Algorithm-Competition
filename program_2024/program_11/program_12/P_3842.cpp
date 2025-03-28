#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];

    vector<vector<int>> dp(n + 1, vector<int>(2, INT32_MAX));
    dp[1][0] = r[1] * 2 - l[1] - 1, dp[1][1] = r[1] - 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][0] + abs(l[i - 1] - r[i]) + (r[i] - l[i]) + 1, dp[i - 1][1] + abs(r[i - 1] - r[i]) + (r[i] - l[i]) + 1);
        dp[i][1] = min(dp[i - 1][0] + abs(l[i - 1] - l[i]) + (r[i] - l[i]) + 1, dp[i - 1][1] + abs(r[i - 1] - l[i]) + (r[i] - l[i]) + 1);
    }
    dp[n][0] += n - l[n];
    dp[n][1] += n - r[n];
    cout << min(dp[n][0], dp[n][1]) << "\n";
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