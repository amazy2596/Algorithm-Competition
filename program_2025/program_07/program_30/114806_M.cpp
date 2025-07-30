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
    vector<int> a(n + 1), b(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        d[i] = a[i] - b[i];
    }

    int offset = 1e4;
    vector<int> dp(2 * offset + 1, -inf);
    dp[offset] = 0;
    for (int k = 1; k <= n; k++)
    {
        if (d[k] < 0)
        {
            for (int i = 0; i - d[k] <= 2 * offset; i++)
            {
                if (dp[i - d[k]] != -inf)
                    dp[i] = max(dp[i], dp[i - d[k]] + a[k]);
            }
        }
        else 
        {
            for (int i = 2 * offset; i - d[k] >= 0; i--)
            {
                if (dp[i - d[k]] != -inf)
                {
                    dp[i] = max(dp[i], dp[i - d[k]] + a[k]);
                }
            }
        }
    }

    cout << dp[offset] << "\n"; 
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}