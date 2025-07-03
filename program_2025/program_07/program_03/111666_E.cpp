#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int K = 20;
const int N = 1e5 + 5;
vector<vector<int>> dp(K, vector<int>(N, inf));

void init()
{
    for (int i = 1; i < N; i++)
        dp[1][i] = i - 1;

    for (int k = 2; k < K; k++)
    {
        for (int i = 1; i < N; i++)
        {
            if (dp[k - 1][i] == inf)
                continue;
            for (int j = 2; i * j < N; j++)
            {
                dp[k][i * j] = min(dp[k][i * j], dp[k - 1][i] + j - 1);
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int ans = inf;
    for (int k = 1; k <= min(K - 1, n); k++)
        ans = min(ans, dp[k][m]);

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}