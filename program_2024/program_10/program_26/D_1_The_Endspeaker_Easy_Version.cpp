#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), pre(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = pre[i - 1] + a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    vector<int> dp(n + 1, 1e18);
    dp[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int pos = lower_bound(pre.begin(), pre.end(), pre[j] - b[i]) - pre.begin() + 1;
            dp[j] = min(dp[j], dp[pos - 1] + m - i);
        }
    }
    cout << (dp[n] == 1e18 ? -1 : dp[n]) << "\n";
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