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
    int n, M, T;
    cin >> n >> M >> T;
    vector<int> m(n + 1), t(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> m[i] >> t[i];

    vector<vector<int>> dp(M + 1, vector<int>(T + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = M; j >= m[i]; j--)
        {
            for (int k = T; k >= t[i]; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - m[i]][k - t[i]] + 1);
            }
        }
    }

    cout << dp[M][T] << "\n";
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