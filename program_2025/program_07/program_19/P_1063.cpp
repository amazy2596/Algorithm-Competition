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
    vector<pair<int, int>> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        if (i <= n)
            cin >> a[i].first;
        else 
            a[i].first = a[i - n].first;
        a[i - 1].second = a[i].first;
    }

    int m = 2 * n;
    vector<vector<int>> dp(m + 1, vector<int>(m + 1));
    for (int len = 2; len <= m; len++)
    {
        for (int l = 1; l + len - 1 <= m; l++)
        {
            int r = l + len - 1;
            for (int p = l; p < r; p++)
            {
                int m = a[l].first;
                int r1 = a[p].second;
                int r2 = a[p + 1].first;
                int n = a[r].second;

                if (r1 == r2)
                    dp[l][r] = max(dp[l][r], dp[l][p] + dp[p + 1][r] + m * r1 * n);
            }
        }
    }

    int ans = 0;
    for (int l = 1; l + n - 1 <= m; l++)
    {
        int r = l + n - 1;
        ans = max(ans, dp[l][r]);
    }

    cout << ans << '\n';
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