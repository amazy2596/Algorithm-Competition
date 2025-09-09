// Problem: D. A Cruel Segment's Thesis
// URL: https://codeforces.com/contest/2140/problem/D
// Author: amazy
// Date: 2025-09-09 23:43:28

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
    i64 ans = 0;
    vector<pair<i64, i64>> a(n);
    for (int i = 0; i < n; i++)
    {
        i64 l, r;
        cin >> l >> r;
        a[i] = {l, r};
        ans += r - l;
    }

    sort(a.begin(), a.end(), [&](pair<i64, i64> &x, pair<i64, i64> &y) 
    {
        return x.first + x.second > y.first + y.second;
    });

    if (n % 2 == 0)
    {
        i64 add = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < n / 2)
                add += a[i].second;
            else 
                add -= a[i].first;
        }
        ans += add;
    }
    else 
    {
        int half = n / 2;
        i64 add = 0;
        i64 pre = 0, suf = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < half)
                pre += a[i].second;
            else if (i > half)
                suf += a[i].first;
        }
        for (int i = 0; i < n; i++)
        {
            i64 cpre = pre, csuf = suf;
            if (i < half)
            {
                cpre -= a[i].second;
                cpre += a[half].second;
            }
            else if (i > half)
            {
                csuf -= a[i].first;
                csuf += a[half].first;
            }
            add = max(add, cpre - csuf);
        }
        ans += add;
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}