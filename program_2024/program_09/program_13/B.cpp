#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a, b;
    int ans = 0, sum = 0, m = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y <= k)
        {
            ans += x;
            sum += k - y;
        }
        else 
        {
            a.push_back(x);
            b.push_back(y - k);
        }
    }
    int cur = 0;
    vector<int> dp(2e5 + 10);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = sum; j >= b[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - b[i]] + a[i]);
            cur = max(cur, dp[j]);
        }
    }
    cout << ans + cur << "\n";
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