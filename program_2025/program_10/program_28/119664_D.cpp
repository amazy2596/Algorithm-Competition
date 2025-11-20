// Problem: x_to_y_2
// URL: https://ac.nowcoder.com/acm/contest/119664/D
// Author: amazy
// Date: 2025-10-28 16:50:57

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
    i64 x, y;
    cin >> x >> y;
    
    int ans = 0;
    while (x)
    {
        bool f = 1;
        for (int k = 0; k < 64; k++)
        {
            if ((x >> k & 1) == 1 && (y >> k & 1) == 0)
            {
                f = 0;
                break;
            }
        }

        if (f)
        {
            if (x == y) cout << ans << "\n";
            else cout << ans + 1 << "\n";
            return;
        }

        ans++;
        x >>= 1;
    }

    if (x == y) cout << ans << "\n";
    else cout << ans + 1 << "\n";
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