// Problem: 白绝大军
// URL: https://ac.nowcoder.com/acm/contest/117762/B
// Author: amazy
// Date: 2025-09-26 19:27:55

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
    i64 n, t;
    cin >> n >> t;
    vector<pair<i64, i64>> p(n);
    i64 sum = 0;
    for (int i = 0; i < n; i++)
        cin >> p[i].first, sum += p[i].first;
    for (int i = 0; i < n; i++)
        cin >> p[i].second;

    if (sum >= t)
    {
        cout << "0\n";
        return;
    }

    i64 ans = 0;
    sort(p.rbegin(), p.rend());
    for (auto [a, b] : p)
    {
        if (a == 0) continue;
        int cnt = min(b, (t - sum + a - 1) / a);
        sum += a * cnt;
        ans += cnt;
        if (sum >= t)
        {
            cout << ans << "\n";
            return;
        }
    }

    cout << "-1\n";
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