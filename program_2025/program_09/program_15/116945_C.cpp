// Problem: 小红的整数三角形
// URL: https://ac.nowcoder.com/acm/contest/116945/C
// Author: amazy
// Date: 2025-09-15 09:54:32

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
    i64 x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2)
        cout << x1 + 2 << " " << y1 << "\n";
    else if (y1 == y2)
        cout << x1 << " " << y1 + 2 << "\n";
    else if (y2 < y1)
        cout << x1 << " " << y2 - abs(y1 - y2) << "\n";
    else 
        cout << x2 << " " << y1 - abs(y1 - y2) << "\n";
}

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}