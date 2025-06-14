#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int m, s, t;
    cin >> m >> s >> t;
    vector<array<int, 2>> dp(m + 1);
    int cur = 0;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j <= m; j++)
            dp[j][cur ^ 1] = -1;

        for (int j = 0; j <= m; j++)
        {
            int pos = dp[j][cur];

            dp[j][cur ^ 1] = max(dp[j][cur ^ 1], pos + 17);

            if (j >= 10)
                dp[j - 10][cur ^ 1] = max(dp[j - 10][cur ^ 1], pos + 60);

            dp[min(m, j + 4)][cur ^ 1] = max(dp[min(m, j + 4)][cur], pos);
        }

        for (int j = 0; j <= m; j++)
        {
            if (dp[j][cur ^ 1] >= s)
            {
                cout << "Yes\n";
                cout << i << "\n";
                return;
            }
        }

        cur ^= 1;
    }

    int mx = -inf;
    for (int j = 0; j <= m; j++)
        mx = max(mx, dp[j][cur]);

    cout << "No\n";
    cout << mx << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}