#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const i64 mod = 998244353;

i64 fast_pow(i64 a, i64 b)
{
    i64 res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

void solve()
{
    i64 n;
    cin >> n;

    if (n < 3)
    {
        cout << "0\n";
        return;
    }

    i64 ans = fast_pow(26, n);
    i64 tmp1 = fast_pow(23, n);
    i64 tmp2 = fast_pow(24, n) - fast_pow(23, n);
    i64 tmp3 = ((fast_pow(25, n) - tmp2 - tmp2 - tmp1) % mod + mod) % mod;

    ans = (ans - 3 * tmp3 + mod) % mod;
    ans = (ans - 3 * tmp2 + mod) % mod;
    ans = (ans - tmp1 + mod) % mod;

    cout << ans % mod << "\n";
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