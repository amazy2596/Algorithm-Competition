#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i];

    vector dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        dp[i][i] = (n & 1 ? 0 : a[i]);

    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            if ((n - len) % 2 == 0)
                dp[l][r] = (a[l] >= a[r] ? dp[l + 1][r] : dp[l][r - 1]);
            else 
                dp[l][r] = max(a[l] + dp[l + 1][r], a[r] + dp[l][r - 1]);
        }
    }

    cout << sum - dp[1][n] << " " << dp[1][n] << "\n";
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