// Problem: C1. The Cunning Seller (easy version)
// URL: https://codeforces.com/contest/2132/problem/C1
// Author: amazy
// Date: 2025-08-21 23:05:39

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

    // for (int i = 0; i < 30; i++)
    // {
    //     i64 fee = pow(3, i + 1) + (i == 0 ? 0 : i * pow(3, i - 1));
    //     i64 num = pow(3, i);

    //     cout << "fee: " << fee << " num: " << num << "\n"; 
    //     cout << "bili: " << fee * 1.0L / num << "\n\n";
    // }

    i64 ans = 0;
    int cur = 0;
    while (cur < n)
    {
        for (int k = 30; k >= 0; k--)
        {
            i64 add = pow(3, k);
            if (cur + add <= n)
            {
                cur += add;
                if (k == 0)
                    ans += 3;
                else 
                    ans += pow(3, k + 1) + k * pow(3, k - 1);
                break;
            }
        }
    }

    cout << ans << "\n";
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