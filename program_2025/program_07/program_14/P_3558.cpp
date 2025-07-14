#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
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

    vector<array<int, 3>> dp(n + 1, {inf, inf, inf});
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    dp[1][a[1] + 1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == -1)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][2] = dp[i - 1][2] + 2;
        }
        else if (a[i] == 0)
        {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]);
            dp[i][2] = dp[i - 1][2] + 1;
        }
        else if (a[i] == 1)
        {
            dp[i][0] = dp[i - 1][0] + 2;
            dp[i][1] = dp[i - 1][0] + 1;
            dp[i][2] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        }
    }

    int ans = min({dp[n][0], dp[n][1], dp[n][2]});
    if (ans >= inf)
        cout << "BRAK\n";
    else 
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