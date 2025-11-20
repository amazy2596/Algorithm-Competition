// Problem: C. Maximum GCD on Whiteboard
// URL: https://codeforces.com/contest/2156/problem/C
// Author: amazy
// Date: 2025-11-06 10:32:24

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), f(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }

    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + f[i];

    for (int g = n; g >= 1; g--)
    {
        int bad = pre[min(4 * g - 1, n)];
        if (g <= n) bad -= f[g];
        if (2 * g <= n) bad -= f[2 * g];
        if (3 * g <= n) bad -= f[3 * g];
        if (bad <= k)
        {
            cout << g << "\n";
            return;            
        }
    }
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