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
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    vector<array<int, 2>> dp(n + 1, {inf, inf});
    vector<array<string, 2>> status(n + 1);
    dp[0][0] = dp[0][1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int last = 0; last < 2; last++)
        {
            for (int cur = 0; cur < 2; cur++)
            {
                int score = 0;
                string tmp = status[i - 1][last];
                for (int j = 0; j < tmp.size(); j++)
                {
                    int x = p[j + 1], y = (cur == 0 ? p[i] : 2 * n - p[i]);
                    if (tmp[j] == '1')
                        x = 2 * n - x;
                    score += (x > y);
                }

                if (dp[i - 1][last] + score < dp[i][cur])
                {
                    dp[i][cur] = min(dp[i][cur], dp[i - 1][last] + score);
                    status[i][cur] = status[i - 1][last] + (cur == 0 ? "0" : "1");
                }
            }
        }
    }

    cout << min(dp[n][0], dp[n][1]) << "\n";
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