// Problem: 小彩的数组构造
// URL: https://ac.nowcoder.com/acm/contest/119273/E
// Author: amazy
// Date: 2025-10-28 17:09:12

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
    int a, b, c;
    cin >> a >> b >> c;

    if (b > a || c > a)
    {
        cout << "-1\n";
        return;
    }

    int n = a + 2;
    vector<int> v(n + 1, 1);
    
    for (int i = 1; i <= b + 2; i++) v[i] *= 2;
    for (int i = 1; i <= c + 2; i++) v[i] *= 3;

    for (int i = b + 1; i + 2 <= n; i++)
    {
        while ((v[i] + v[i + 1] + v[i + 2]) % 2 == 0) 
        {
            v[i + 2] += 3;
        }
    }
    for (int i = c + 1; i + 2 <= n; i++)
    {
        while ((v[i] + v[i + 1] + v[i + 2]) % 3 == 0) 
        {
            v[i + 2] += 2;
        }
    }
    cout << n << "\n";
    for (int i = 1; i <= n; i++) cout << v[i] << " ";
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