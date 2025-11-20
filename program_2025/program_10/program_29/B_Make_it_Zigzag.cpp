// Problem: B. Make it Zigzag
// URL: https://codeforces.com/contest/2154/problem/B
// Author: amazy
// Date: 2025-10-29 11:00:44

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
    vector<int> b(n + 2, inf);
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        mx = max(mx, b[i]);
        if (i % 2 == 0) b[i] = mx;
    }

    int ans = 0;
    for (int i = 1; i <= n; i += 2)
    {
        ans += max(0, b[i] - min(b[i - 1], b[i + 1]) + 1);
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