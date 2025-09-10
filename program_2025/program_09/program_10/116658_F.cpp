// Problem: AND VS MEX
// URL: https://ac.nowcoder.com/acm/contest/116658/F
// Author: amazy
// Date: 2025-09-10 12:32:30

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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k = bit_width((u64)n) + 1;
    int all = (1LL << k);
    vector<int> dp(all, all - 1);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        dp[a[i]] = a[i];

    for (int b = 0; b < k; b++)
    {
        for (int i = 0; i < all; i++)
        {
            if ((i & (1 << b)) == 0)
                dp[i] &= dp[i | (1 << b)];
        }
    }

    for (int i = 0; i <= n; i++)
    {
        if (dp[i] != i)
        {
            cout << i << "\n";
            return;
        }
    }
    cout << n + 1 << "\n";
}

int main()
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