#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };



void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (m == 1)
    {
        int ans = *max_element(a.begin() + 1, a.end()) - a[1];
        for (int i = 2; i <= n; i++)
            ans += max(0, a[i - 1] - a[i]);

        cout << ans << "\n";
    }
    else 
    {
        int ans = inf;
        for (int x = 1; x <= 200; x++)
        {
            for (int y = 1; y <= x; y++)
            {
                vector<array<int, 2>> dp(n + 1, {inf, inf});
                dp[0][0] = dp[0][1] = 0;
                if (x >= a[1])
                    dp[1][0] = x - a[1];
                if (y >= a[1])
                    dp[1][1] = y - a[1];
                for (int i = 2; i <= n; i++)
                {
                    if (x >= a[i])
                    {
                        dp[i][0] = min({dp[i][0], dp[i - 1][0] + max(0, (x - a[i]) - (x - a[i - 1])), dp[i - 1][1] + max(0, (x - a[i]) - (y - a[i - 1]))});
                    }

                    if (y >= a[i])
                    {
                        dp[i][1] = min({dp[i][1], dp[i - 1][0] + max(0, (y - a[i]) - (x - a[i - 1])), dp[i - 1][1] + max(0, (y - a[i]) - (y - a[i - 1]))});
                    }
                }

                ans = min({ans, dp[n][0], dp[n][1]});
            }
        }

        cout << ans << "\n";
    }
}

int main()
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