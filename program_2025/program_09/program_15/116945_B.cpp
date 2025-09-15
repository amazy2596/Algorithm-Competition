// Problem: 小红的好点对
// URL: https://ac.nowcoder.com/acm/contest/116945/B
// Author: amazy
// Date: 2025-09-15 09:43:46

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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    auto check = [&](int x, int y) 
    {
        int res = 0;
        for (auto [x1, y1] : a)
        {
            int dist = abs(x - x1) + abs(y - y1);
            res += (dist == 1);
        }

        return res;
    };

    int ans = 0;
    for (auto [x, y] : a)
        ans += check(x, y);

    cout << ans / 2 << "\n";
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