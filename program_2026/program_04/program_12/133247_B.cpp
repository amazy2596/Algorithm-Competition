// Problem: 卡牌染色
// URL: https://ac.nowcoder.com/acm/contest/133247/B
// Author: amazy
// Date: 2026-04-12 15:39:33

#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 998244353;
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

int N = 2e5 + 5;
vector<i64> f(N + 1), pre(N + 1);

void solve()
{
    int n;
    cin >> n;
    cout << f[n] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    f[0] = 0, f[1] = 1;
    pre[0] = 0, pre[1] = 1;
    for (int i = 2; i <= N; i++) 
    {
        f[i] = (2 * pre[i - 2] + i) % mod * inv(i) % mod;
        f[i] %= mod;
        pre[i] = (pre[i - 1] + f[i]) % mod;
    }

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}