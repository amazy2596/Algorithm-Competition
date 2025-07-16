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

const int mod = 1e8;

void solve()
{
    int n, f;
    cin >> n >> f;
    vector<int> r(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(f));
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
        r[i] %= f;
        dp[i][r[i]] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < f; j++)
        {
            dp[i][j] += (dp[i - 1][j] + dp[i - 1][(j - r[i] + f) % f]) % mod;
        }
    }

    cout << dp[n][0] << "\n";
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