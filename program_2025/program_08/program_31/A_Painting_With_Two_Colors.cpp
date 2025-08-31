// Problem: A. Painting With Two Colors
// URL: https://codeforces.com/contest/2134/problem/A
// Author: amazy
// Date: 2025-08-31 21:08:17

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
    int n, a, b;
    cin >> n >> a >> b;
    if (n % 2 != b % 2)
    {
        cout << "NO\n";
        return;
    }

    if (a <= b)
        cout << "YES\n";
    else if (n % 2 == a % 2)
        cout << "YES\n";
    else 
        cout << "NO\n";
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