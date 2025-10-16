// Problem: 小红的k次方
// URL: https://ac.nowcoder.com/acm/contest/119225/C
// Author: amazy
// Date: 2025-10-16 10:58:57

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
    
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        while (x % 2 == 0)
            mp[2]++, x /= 2;
        while (x % 3 == 0)
            mp[3]++, x /= 3;
        while (x % 5 == 0)
            mp[5]++, x /= 5;
    }
    
    cout << min({mp[2], mp[3], mp[5]}) << "\n";
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