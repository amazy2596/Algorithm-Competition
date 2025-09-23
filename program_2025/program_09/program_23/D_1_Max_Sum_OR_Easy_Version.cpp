// Problem: D1. Max Sum OR (Easy Version)
// URL: https://codeforces.com/contest/2146/problem/D1
// Author: amazy
// Date: 2025-09-23 09:09:50

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
    int L, R;
    cin >> L >> R;
    int n = R - L + 1;
    vector<int> a(n), b(n);
    iota(a.begin(), a.end(), L);
    // iota(b.begin(), b.end(), l);

    // 15 14 13 12 11 10 9 8 7 6  5  4  3  2  1  0
    //  0  1  2  3  4  5 6 7 8 9 10 11 12 13 14 15

    // 13 12 11 10 15 14
    // 10 11 12 13 14 15

    // 7 6 5 4 3 2 1 0
    // 0 1 2 3 4 5 6 7

    // 4 3 6 5 7
    // 3 4 5 6 7

    // 1 0 5 4 3 2       9 8 7 6
    // 0 1 2 3 4 5       6 7 8 9

    // int ans = 0;
    // do
    // {
    //     auto tmp = a;
    //     int sum = 0;
    //     for (int i = 0; i < n; i++)
    //         sum += (tmp[i] | b[i]);

    //     if (sum == 90)
    //     {
    //         vector<int> tar = {13, 14, 12, 10, 11};
    //         bool f = 0;
    //         for (int i = 0; i < tar.size(); i++)
    //             if (tmp[i] != tar[i]) f = 1;

    //         // if (f) continue;

    //         for (int i = 0; i < n; i++)
    //             cout << tmp[i] << " \n"[i == n - 1];
    //     }
    //     ans = max(ans, sum);
    // } while (next_permutation(a.begin(), a.end()));
    // cout << ans << "\n";

    auto get = [&](int x, int k)
    {
        return (x >> k) & 1;
    };
    
    auto dfs = [&](auto dfs, i64 l, i64 r, int b) -> void
    {
        if (l > r) return;
        if (l == r)
        {
            a[l - L] = l;
            return;
        }
        int mid = l;
        while (mid + 1 <= r && get(mid + 1, b) == get(l, b))
            mid++;

        if (mid == r)
        {
            dfs(dfs, l, r, b - 1);
            return;
        }

        i64 half_l = mid + 1;
        i64 half_r = mid;

        while (half_l > l && half_r < r)
        {
            half_l--;
            half_r++;
            a[half_l - L] = half_r;
            a[half_r - L] = half_l;
        }

        dfs(dfs, l, half_l - 1, b - 1);
        dfs(dfs, half_r + 1, r, b - 1);
    };
    
    dfs(dfs, L, R, 30);
    i64 ans = 0;
    for (int i = 0; i < n; i++)
        ans += (a[i] | i);
    cout << ans << "\n";

    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];
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