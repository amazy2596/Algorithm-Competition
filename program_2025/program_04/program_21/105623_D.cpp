#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> dp(n + 1, -1e18);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i], dp[i - 1] + a[i]);

        if (i >= 2)
            dp[i] = max(dp[i], dp[i - 2]);
        if (i >= 3)
            dp[i] = max(dp[i], dp[i - 3]);
    }

    cout << dp[n] << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}