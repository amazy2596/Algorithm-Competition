#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1), preA(n + 1), preB(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], preA[i] = preA[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i], preB[i] = preB[i - 1] + b[i];

    vector<array<int, 2>> dp(n + 1);
    dp[0][1] = INT32_MIN;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + a[i], (dp[i - 1][1] >= k ? dp[i - 1][1] + a[i] - k : INT32_MIN));
        dp[i][1] = max(dp[i - 1][1] + b[i], (dp[i - 1][0] >= k ? dp[i - 1][0] + b[i] - k : INT32_MIN));
    }

    cout << max(dp[n][0], dp[n][1]) << "\n";
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