// Problem: 小苯的01矩阵构造
// URL: https://ac.nowcoder.com/acm/contest/115861/C
// Author: amazy
// Date: 2025-08-20 22:47:45

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
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    if (k % 2 == 1)
    {
        cout << "-1\n";
        return;
    }
    a[1][1] = 1;
    int cur = 2;
    for (int i = 2; i <= n; i++)
    {
        if (cur < k)
        {
            a[i][1] = 1;
            if (i % 2 == 1)
                cur += 2;
        }
        else 
            break;
    }
    for (int j = 2; j <= n; j++)
    {
        if (cur < k)
        {
            a[1][j] = 1;
            if (j % 2 == 1)
                cur += 2;
        }
        else 
            break;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j];
        }
        cout << "\n";
    }
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