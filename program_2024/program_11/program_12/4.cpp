#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), w(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];
    vector<int> dp(m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 0; k <= s[i]; k++)
            {
                if (j >= k * v[i])
                    dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
            }
        }
    }
    cout << dp[m] << "\n";
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