// Problem: D. Not Alone
// URL: https://codeforces.com/contest/2153/problem/D
// Author: amazy
// Date: 2025-10-23 11:21:34

// Problem: D. Not Alone
// URL: https://codeforces.com/contest/2153/problem/D
// Author: amazy
// Date: 2025-10-22 11:33:42

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

int cost(int a, int b)
{
    return abs(a - b);
}

int cost(int a, int b, int c)
{
    return min({abs(a - b) + abs(a - c), abs(b - a) + abs(b - c), abs(c - a) + abs(c - b)});
}

void solve()
{
    int n;
    cin >> n;
    vector<i64> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    i64 ans = INF;
    vector<i64> dp(n + 1, INF);

    for (int j = 0; j < 3; j++)
    {
        v.push_back(v[1]);
        v.erase(v.begin() + 1);
        dp.assign(n + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i >= 2) 
            {
                // cout << "cost2: " << cost(v[i - 1], v[i]) << "\n";
                dp[i] = min(dp[i], dp[i - 2] + cost(v[i - 1], v[i]));
            }
            if (i >= 3) 
            {
                // cout << "cost3: " << cost(v[i - 2], v[i - 1], v[i]) << "\n";
                dp[i] = min(dp[i], dp[i - 3] + cost(v[i - 2], v[i - 1], v[i]));
            }
        }
        ans = min(ans, dp[n]);
    }

    cout << ans << "\n";
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