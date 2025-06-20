#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct node
{
    int v, m, w;
};

void solve()
{
    int n, v, m;
    cin >> n >> v >> m;
    vector<node> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].v >> a[i].m >> a[i].w;

    vector<vector<int>> dp(v + 1, vector<int>(m + 1, -inf));
    dp[0][0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = v; j >= a[i].v; j--)
        {
            for (int k = m; k >= a[i].m; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - a[i].v][k - a[i].m] + a[i].w);
                ans = max(ans, dp[j][k]);
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
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}