// Problem: 牛牛战队的比赛地
// URL: https://ac.nowcoder.com/acm/contest/120454/F
// Author: amazy
// Date: 2025-11-12 19:53:08

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-5;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (auto &[x, y] : p) cin >> x >> y;

    auto check = [&](double r)
    {
        double L = -INF, R = INF;
        for (auto [x, y] : p)
        {
            if (r < fabs(y)) return false;
            L = max(L, x - sqrt(r * r - y * y));
            R = min(R, x + sqrt(r * r - y * y));
        }

        return L <= R;
    };

    double l = -INF, r = INF;
    for (int i = 0; i < 1000; i++)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else 
            l = mid;
    }

    cout << fixed << setprecision(4) << l << "\n";
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