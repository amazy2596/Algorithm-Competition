// Problem: 小红的马
// URL: https://ac.nowcoder.com/acm/contest/116945/D
// Author: amazy
// Date: 2025-09-15 10:10:00

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
    map<pair<int, int>, int> exist;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        exist[{x, y}]++;
        for (auto [dx, dy] : vector<pair<int, int>> {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}})
        {
            int nx = x + dx, ny = y + dy;
            mp[{nx, ny}]++;
        }
    }

    int u, v;
    int mx = 0;
    for (auto [p, val] : mp)
    {
        auto [x, y] = p;
        if (exist.find({x, y}) != exist.end()) continue;
        if (x <= 0 || y <= 0) continue;
        if (val > mx)
        {
            u = x;
            v = y;
            mx = val;
        }
    }

    cout << u << " " << v << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}