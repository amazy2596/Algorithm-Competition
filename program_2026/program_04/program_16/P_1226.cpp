// Problem: 【模板】快速幂
// URL: https://www.luogu.com.cn/problem/P1226
// Author: amazy
// Date: 2026-04-16 16:06:39

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

i64 p;

i64 fast_pow(i64 a, i64 b)
{
    i64 res = 1;
    while (b)
    {
        if (b & 1) res = (res * a) % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void solve()
{
    i64 a, b;
    cin >> a >> b >> p;
    cout << a << "^" << b  << " mod " << p << "=" << fast_pow(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}