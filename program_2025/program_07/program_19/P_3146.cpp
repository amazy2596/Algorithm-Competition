#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        dp[i][i] = a[i], ans = max(ans, a[i]);

    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            for (int p = l; p < r; p++)
            {
                if (dp[l][p] == dp[p + 1][r] && dp[l][p] > 0)
                {
                    dp[l][r] = max(dp[l][r], dp[l][p] + 1);
                    ans = max(ans, dp[l][r]);
                }
            }
        }
    }

    cout << ans << "\n";
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