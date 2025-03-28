#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int t, m;
    cin >> t >> m;
    vector<int> a(m + 1), b(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> a[i] >> b[i];
    
    vector<int> dp(t + 1);
    for (int i = 1; i <= m; i++)
    {
        for (int j = a[i]; j <= t; j++)
        {
            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
        }
    }
    cout << dp[t] << "\n";
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