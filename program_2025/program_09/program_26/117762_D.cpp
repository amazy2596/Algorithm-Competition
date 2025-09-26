// Problem: 谁敢动资本的蛋糕
// URL: https://ac.nowcoder.com/acm/contest/117762/D
// Author: amazy
// Date: 2025-09-26 19:47:07

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
    vector<i64> a(n + 1);

    // x + y = x ^ y + 2 * (x & y)
    i64 s = 0, t = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
        t ^= a[i];
    }

    cout << s - t << "\n";
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