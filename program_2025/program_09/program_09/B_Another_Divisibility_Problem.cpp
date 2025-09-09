// Problem: B. Another Divisibility Problem
// URL: https://codeforces.com/contest/2140/problem/B
// Author: amazy
// Date: 2025-09-09 22:42:04

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
    i64 x;
    cin >> x;
    cout << 8 * x << "\n";
    // i64 y = 8 * x;
    // string s = to_string(x) + to_string(y);
    // i64 val = 0;
    // for (int i = 0; i < s.size(); i++)
    //     val = (val * 10 + (s[i] - '0'));
    // if (val % (x + y) == 0)
    //     cout << "YES\n";
    // else 
    //     cout << "NO\n";
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