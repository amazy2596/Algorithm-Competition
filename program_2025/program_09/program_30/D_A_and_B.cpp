// Problem: D. A and B
// URL: https://codeforces.com/contest/2149/problem/D
// Author: amazy
// Date: 2025-09-30 18:41:12

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
    string s;
    cin >> s;
    s = " " + s;

    vector<i64> preA(n + 1), numA(n + 1), preB(n + 1), numB(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'a') 
        {
            preA[i] = preA[i - 1] + i;
            numA[i] = numA[i - 1] + 1;

            preB[i] = preB[i - 1];
            numB[i] = numB[i - 1];
        }
        else 
        {
            preB[i] = preB[i - 1] + i;
            numB[i] = numB[i - 1] + 1;

            preA[i] = preA[i - 1];
            numA[i] = numA[i - 1];
        }
    }

    i64 ans = INF;
    for (i64 i = 1; i <= n; i++)
    {
        i64 cur = 0;
        if (s[i] == 'a')
        {
            cur += numA[i - 1] * i - preA[i - 1] - (1 + numA[i - 1]) * numA[i - 1] / 2;
            i64 tmp = numA[n] - numA[i];
            cur += (preA[n] - preA[i]) - tmp * i - (1 + tmp) * tmp / 2;
        }
        else 
        {
            cur += numB[i - 1] * i - preB[i - 1] - (1 + numB[i - 1]) * numB[i - 1] / 2;
            i64 tmp = numB[n] - numB[i];
            cur += (preB[n] - preB[i]) - tmp * i - (1 + tmp) * tmp / 2;
        }
        ans = min(ans, cur);
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