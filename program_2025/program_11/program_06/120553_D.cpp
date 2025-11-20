// Problem: 小红的区间相交
// URL: https://ac.nowcoder.com/acm/contest/120553/D
// Author: amazy
// Date: 2025-11-06 10:59:59

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
    vector<pair<int, int>> seg(n);
    int L = -inf, R = inf;
    for (auto &[l, r] : seg) 
    {
        cin >> l >> r;
        L = max(L, l);
        R = min(R, r);
    }
    sort(seg.begin(), seg.end());

    for (int i = 1; i < n; i++)
    {
        if (seg[i - 1].first < seg[i].first && seg[i - 1].second > seg[i].second)
        {
            cout << "No\n";
            return;
        }
    }

    cout << (L <= R ? "Yes\n" : "No\n");
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