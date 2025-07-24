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
    int n, x;
    cin >> n >> x;
    x = x - (n - 1) * (n + 2) / 2;

    if (x < 0 || n == 1)
    {
        cout << "0\n";
        return;
    }

    vector<int> dp(x + 1, 1);
    for (int i = 1; i <= n - 2; i++)
    {
        for (int j = i; j <= x; j++)
        {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }

    int tmp = n - 1;
    for (int j = tmp; j <= x; j++)
        dp[j] = (dp[j] + dp[j - tmp]) % mod;
    for (int j = tmp; j <= x; j++)
        dp[j] = (dp[j] + dp[j - tmp]) % mod;

    cout << dp[x] % mod << "\n";
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