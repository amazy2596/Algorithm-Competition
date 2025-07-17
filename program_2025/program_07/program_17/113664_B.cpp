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
    int a, b, c1, c2, c3;
    cin >> a >> b >> c1 >> c2 >> c3;

    vector<array<int, 2>> dp(1e3 + 5, {inf, inf});
    int cur = 0;
    dp[a][cur ^ 1] = 0;
    for (int i = 1; i <= 1e3 + 5; i++)
    {
        for (int j = 1; j <= 1e3; j++)
        {
            if (dp[j - 1][cur ^ 1] != inf)
                dp[j][cur] = min(dp[j][cur], dp[j - 1][cur ^ 1] + c1);
            if (dp[j + 1][cur ^ 1] != inf)
                dp[j][cur] = min(dp[j][cur], dp[j + 1][cur ^ 1] + c2);
            if (j % 2 == 0 && dp[j / 2][cur ^ 1] != inf)
                dp[j][cur] = min(dp[j][cur], dp[j / 2][cur ^ 1] + c3);
        }

        cur ^= 1;
    }

    cout << min(dp[b][0], dp[b][1]) << "\n";

    // if (b <= a)
    // {
    //     cout << (a - b) * c2 << "\n";
    //     return;
    // }

    // int cost = 0, ans = inf;
    // while (a != b)
    // {
    //     if (a + a > b)
    //     {
    //         ans = min(ans, cost + (b - a) * c1);
    //         if (b % 2 == 0)
    //             ans = min(ans, cost + (a - b / 2) * c2 + c3);

    //         a++;
    //         cost += c1;
    //         continue;
    //     }

    //     int cost1 = a * c1, cost2 = c3;
    //     if (cost1 <= cost2)
    //         cost += cost1;
    //     else 
    //         cost += cost2;
    //     a += a;
    // }

    // cout << min(cost, ans) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}