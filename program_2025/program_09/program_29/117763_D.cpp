// Problem: 小红的好数对
// URL: https://ac.nowcoder.com/acm/contest/117763/D
// Author: amazy
// Date: 2025-09-29 11:14:20

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 11;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> cntA(mod);
    vector<array<int, mod>> cntB(2);
    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int rem = a[i] % mod;
        int len = to_string(a[i]).length();
        ans += cntB[0][(mod - rem) % mod] + cntB[1][rem];

        if (len & 1) ans += cntA[rem];
        else ans += cntA[(mod - rem) % mod];

        cntA[rem]++;
        cntB[len % 2][rem]++;
    }

    cout << ans << "\n";
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