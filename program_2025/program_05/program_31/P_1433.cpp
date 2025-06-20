#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    int n;
    cin >> n;
    vector<pair<double, double>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    auto calc = [&](double x1, double y1, double x2, double y2)
    {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };

    vector dp(1 << n, vector<double>(n, inf));
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = calc(0, 0, a[i].first, a[i].second);

    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!((mask >> j) & 1))
                continue;

            if (dp[mask][j] >= inf)
                continue;
            
            for (int k = 0; k < n; k++)
            {
                if (((mask >> k) & 1))
                    continue;
                
                dp[mask | (1 << k)][k] = min(dp[mask | (1 << k)][k], dp[mask][j] + calc(a[j].first, a[j].second, a[k].first, a[k].second));
            }
        }
    }

    cout << fixed << setprecision(2) << *min_element(dp[(1 << n) - 1].begin(), dp[(1 << n) - 1].end()) << "\n";
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