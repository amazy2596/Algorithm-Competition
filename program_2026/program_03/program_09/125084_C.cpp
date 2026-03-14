// Problem: 小月的计数
// URL: https://ac.nowcoder.com/acm/contest/125084/C
// Author: amazy
// Date: 2026-03-09 16:32:37

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

i64 mod;
i64 fast_pow(i64 a, i64 b) 
{
    i64 res = 1;
    a %= mod;
    while (b) 
    {
        if (b & 1)
            res = (1LL * res * a) % mod;

        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}

i64 inv(i64 x) 
{
    return fast_pow(x, mod - 2);
}

void solve()
{
    i64 a, b;
    cin >> a >> b >> mod;
    vector<i64> cnta(mod), cntb(mod);
    for (int i = 0; i < mod; i++) cnta[fast_pow(i, a)]++;
    for (int i = 0; i < mod; i++) cntb[fast_pow(i, b)]++;
    i64 ans = 0;
    for (int i = 0; i < mod; i++) ans += cnta[i] * cntb[i];
    cout << ans << "\n";
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