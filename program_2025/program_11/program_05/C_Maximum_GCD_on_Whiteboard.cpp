// Problem: C. Maximum GCD on Whiteboard
// URL: https://codeforces.com/contest/2156/problem/C
// Author: amazy
// Date: 2025-11-05 11:14:09

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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    auto can = [&](int x, int g)
    {
        if (x < 3 * g) return false;
        int l = (x - g + 1) / 2;
        int r = x - 2 * g;
        
        int c = (l + g - 1) / g * g;
        return c <= r;
    };

    auto check = [&](int g)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!can(a[i], g) && a[i] % g != 0)
                cnt++;
        }

        return cnt <= k;
    };

    int l = 0, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else 
            r = mid - 1;
    }

    cout << l << "\n";
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