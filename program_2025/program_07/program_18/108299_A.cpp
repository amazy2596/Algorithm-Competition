#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<array<int, 2>> dp(n + 1), f(n + 1);
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        if (x == 0 || x == -1)
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            f[i][0] = (f[i - 1][0] + f[i - 1][1]) % mod;
        }

        if (x == 1 || x == -1)
        {
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] + f[i - 1][0]) % mod;
            f[i][1] = (f[i - 1][1] + f[i - 1][0]) % mod;
        }
    }

    cout << (dp[n][0] + dp[n][1]) % mod << "\n";
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