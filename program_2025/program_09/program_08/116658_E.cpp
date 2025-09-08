// Problem: 小苯的有趣数
// URL: https://ac.nowcoder.com/acm/contest/116658/E
// Author: amazy
// Date: 2025-09-08 22:15:19

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

vector<int> nums = {1, 4, 9, 36, 81, 100, 121, 144, 169, 196, 225, 324, 400, 441, 484, 529, 900, 961, 1521, 1681, 2025, 2304, 2601, 3364, 3481, 3600, 4489, 4624, 5776, 5929, 7225, 7396, 8100, 8836, 9025, 10000, 10201, 10404, 10609, 10816, 11025, 12100, 12321, 12544, 12769, 14400, 14641, 14884, 16900, 17161, 19321, 19600};
vector<vector<int>> dp(105, vector<int>(20005, 0));
void pre()
{
    dp[0][0] = 1;
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 20000; j++)
        {
            if (dp[i][j])
            {
                for (auto num : nums)
                {
                    if (j + num <= 20000)
                        dp[i + 1][j + num] = 1;
                }
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int sum = accumulate(a.begin() + 1, a.end(), 0);
    cout << (dp[n][sum] ? n : n - 1) << "\n";
}

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    pre();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}