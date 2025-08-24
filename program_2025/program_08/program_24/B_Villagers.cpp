// Problem: B. Villagers
// URL: https://codeforces.com/contest/2133/problem/B
// Author: amazy
// Date: 2025-08-24 22:38:44

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
    vector<int> g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> g[i];
    sort(g.rbegin(), g.rend() - 1);

    i64 ans = 0;
    for (int i = 2; i <= n; i += 2)
        ans += g[i - 1];

    if (n % 2 == 1)
        ans += g.back();

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