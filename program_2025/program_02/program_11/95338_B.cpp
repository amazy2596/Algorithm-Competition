#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, c1, c2;
    cin >> n >> c1 >> c2;
    vector a(n + 1, vector<pair<int, int>>(2));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0].first >> a[i][0].second;
        a[i][1] = {a[i][0].second, a[i][0].first};
    }
    
    vector dp(n + 1, vector<int>(2, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = max(c1, 0ll);
        dp[i][1] = max(c1 - c2, 0ll);
    }

    int best = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int s = 0; s < 2; s++)
        {
            best = max(best, dp[i][s]);
            for (int j = i + 1; j <= n; j++)
            {
                for (int t = 0; t < 2; t++)
                {
                    if (a[i][s].first <= a[j][t].first && a[i][s].second <= a[j][t].second)
                    {
                        dp[j][t] = max(dp[j][t], dp[i][s] + (t == 0 ? c1 : max(c1 - c2, 0ll)));
                    }
                }
            }
        }
    }

    cout << n * c1 - best << "\n";
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