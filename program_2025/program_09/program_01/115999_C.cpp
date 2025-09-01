// Problem: I Wanna Beat the Joke
// URL: https://ac.nowcoder.com/acm/contest/115999/C
// Author: amazy
// Date: 2025-09-01 09:44:13

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
    i64 n;
    cin >> n;

    // map<int, int> mp;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (mp.find(i) == mp.end())
    //     {
    //         // if (popcount((size_t)i) == 1)
    //             // cout << i << " " << 4 * i << "\n";
    //         mp[i]++;
    //         mp[4 * i]++;
    //     }
    //     else 
    //     {
    //         // if (popcount((size_t)i) == 1)
    //             // cout << i << " " << i / 4 << "\n";
    //         mp[i]++;
    //         mp[i / 4]++;
    //     }
    // }

    // cout << mp.size() << "\n";

    auto f = [&](i64 n)
    {
        i64 res = 0;
        while (n)
        {
            res += (n - n / 4);
            n /= 16;
        }
        return res;
    };

    i64 ans = n + f(n) - f(n / 4);
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