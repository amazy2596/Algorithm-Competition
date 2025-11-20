// Problem: 小苯的GCD疑问2.0
// URL: https://ac.nowcoder.com/acm/contest/119895/F
// Author: amazy
// Date: 2025-10-28 18:08:27

// Problem: 小苯的GCD疑问1.0
// URL: https://ac.nowcoder.com/acm/contest/119895/E
// Author: amazy
// Date: 2025-10-28 18:00:11

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
    i64 n, k;
    cin >> n >> k;

    i64 ans = 0;
    for (int i = 1; i <= n / k; )
    {
        i64 cnt = n / i;
        i64 j = min(n / k, n / cnt);
        ans = max(ans, j * j * cnt * (cnt + 1) / 2);
        i = j + 1;
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