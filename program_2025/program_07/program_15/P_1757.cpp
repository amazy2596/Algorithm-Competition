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
    int n, m;
    cin >> m >> n;

    map<int, vector<pair<int, int>>> group;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        group[c].emplace_back(a, b);
    }

    vector<array<int, 2>> dp(m + 1);
    int op = 0;
    for (auto &[_, v] : group)
    {
        for (int j = 0; j <= m; j++)
            dp[j][op] = dp[j][op ^ 1];
        for (auto [w, v] : v)
        {
            for (int j = m; j >= w; j--)
            {
                dp[j][op] = max(dp[j][op], dp[j - w][op ^ 1] + v);
            }
        }
        op ^= 1;
    }

    cout << dp[m][op ^ 1] << "\n";
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