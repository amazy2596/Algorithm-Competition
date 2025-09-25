// Problem: 小苯的序列合并
// URL: https://ac.nowcoder.com/acm/contest/117163/F
// Author: amazy
// Date: 2025-09-25 23:43:21

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
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }

    i64 ans = 0;
    for (int b = 30; b >= 0; b--)
    {
        int mask = ans | (1LL << b);
        vector<int> dp(n + 1);
        unordered_set<int> s;
        dp[0] = 1;
        s.insert(0);
        for (int i = 1; i <= n; i++)
        {
            int need = (pre[i] & mask) ^ mask;
            if (s.count(need))
            {
                s.insert(pre[i] & mask);
                dp[i] = 1;
            }
        }

        if (dp[n]) ans = mask;
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