#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;
const int INF = 1e18l;

int bits = 62;
vector dp(bits, vector<int>(bits, INF));

void init()
{
    dp[0][0] = 0;

    for (int x = 0; x < bits; x++)
    {
        for (int i = bits - 1; i >= 0; i--)
        {
            for (int j = bits - 1; j >= 0; j--)
            {
                if (dp[i][j] == INF)
                    continue;
                if (i + x < bits)
                    dp[i + x][j] = min(dp[i + x][j], dp[i][j] + (1ll << x));
                if (j + x < bits)
                    dp[i][j + x] = min(dp[i][j + x], dp[i][j] + (1ll << x));
            }
        }
    }    
}

void solve()
{
    int x, y;
    cin >> x >> y;

    int ans = INF;
    for (int i = 0; i < bits; i++)
    {
        for (int j = 0; j < bits; j++)
        {
            if ((x >> i) == (y >> j))
                ans = min(ans, dp[i][j]);
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
    cin >> T;
    init();
    while (T--)
        solve();
    return 0;
}