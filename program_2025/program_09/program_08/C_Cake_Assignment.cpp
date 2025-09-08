// Problem: C. Cake Assignment
// URL: https://codeforces.com/contest/2139/problem/C
// Author: amazy
// Date: 2025-09-08 22:57:38

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
    i64 k, x;
    cin >> k >> x;
    vector<int> ans;
    i64 half = 1LL << k;
    i64 a = x, b = 2 * half - a;
    while (a != half)
    {
        if (a <= half)
        {
            ans.push_back(1);
            b -= a;
            a *= 2;
        }
        else 
        {
            ans.push_back(2);
            a -= b;
            b *= 2;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << " ";
    cout << "\n";
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