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
    int s, n, m;
    cin >> s >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(s + 1));
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[j][i];
        }
    }

    for (int i = 1; i <= n; i++)
        sort(a[i].begin() + 1, a[i].end());

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= s; k++)
        {
            for (int j = m; j >= 0; j--)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j >= a[i][k] * 2 + 1)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - (a[i][k] * 2 + 1)] + i * k);
            }
        }
    }

    cout << *max_element(dp[n].begin(), dp[n].end()) << "\n";
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