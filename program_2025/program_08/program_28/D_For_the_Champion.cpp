// Problem: D. For the Champion
// URL: https://codeforces.com/contest/2136/problem/D
// Author: amazy
// Date: 2025-08-28 23:13:13

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
    vector<pair<i64, i64>> p;
    i64 s1 = -INF, s2 = -INF;
    for (int i = 0; i < n; i++)
    {
        i64 x, y;
        cin >> x >> y;
        p.push_back({x, y});
        s1 = max(s1, x + y);
        s2 = max(s2, x - y);
    }

    auto query = [&](char ch, i64 k)
    {
        cout << "? " << ch << " " << k << endl;
        i64 res;
        cin >> res;
        return res;
    };

    i64 k = inf;
    query('R', k);
    query('R', k);
    query('U', k);
    i64 d1 = query('U', k);
    query('D', k);
    query('D', k);
    query('D', k);
    i64 d2 = query('D', k);

    i64 a = (d1 - 4 * k + s1);
    i64 b = (d2 - 4 * k + s2);

    i64 x = (a + b) / 2, y = (a - b) / 2;
    cout << "! " << x << " " << y << endl;
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