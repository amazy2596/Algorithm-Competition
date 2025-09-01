// Problem: 小苯的刷怪笼
// URL: https://ac.nowcoder.com/acm/contest/116343/E
// Author: amazy
// Date: 2025-09-01 12:34:10

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
    i64 n, a, k;
    cin >> n >> a >> k;

    if (n == 1)
    {
        if (a == k)
            cout << a << "\n";
        else 
            cout << "-1\n";
        return;
    }
    
    int mn = (a + 1) / 2, mx = a - (n - 1) / 2;
    if (k < mn || k > mx)
    {
        cout << "-1\n";
        return;
    }

    vector<int> v(n, 1);
    v[0] += k - (n + 1) / 2;
    v[1] += (a - k) - (n / 2);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " \n"[i == v.size() - 1];
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