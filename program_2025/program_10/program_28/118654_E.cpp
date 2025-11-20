// Problem: honoka和格点三角形
// URL: https://ac.nowcoder.com/acm/contest/118654/E
// Author: amazy
// Date: 2025-10-28 16:03:00

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
    i64 n, m;
    cin >> n >> m;
    i64 ans = 0;
    if (n == 2 && m == 2)
    {
        cout << "0\n";
        return;
    }
    else if (n == 3)
    {
        if (m == 2)
        {
            cout << "6\n";
            return;
        }
        ans += (m - 4) * 4 * 3 % mod;
        return;
    }
    else if (m == 3)
    {
        swap(n, m);
        return;
    }
    else 
    {

        return;
    }

    ans += (n - 2) * (m - 2) % mod * 4 % mod;
    ans += (n - 4) * (m - 4) % mod * 8 % mod;
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