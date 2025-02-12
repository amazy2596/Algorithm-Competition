#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    
    sort(a.begin() + 1, a.end());

    vector<int> dp(n + 1), mx(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = a[i].first + a[i].second;
        mx[i] = max(mx[i - 1], sum[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (dp[i - 1] >= a[i].first)
            dp[i] = max(dp[i - 1], sum[i]);
        else 
            dp[i] = max({dp[i - 1], a[i].first, mx[i - 1]});
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