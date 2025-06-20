#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 5;
int fact[N + 5], ifact[N + 5];

int fast_pow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

void init()
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
        fact[i] %= mod;
    }
    ifact[N] = fast_pow(fact[N], mod - 2);
    for (int i = N - 1; i >= 0; i--)
    {
        ifact[i] = ifact[i + 1] * (i + 1) % mod;
        ifact[i] %= mod;
    }
}

int c(int n, int m)
{
    return (fact[n] * ((ifact[n - m] * ifact[m]) % mod)) % mod;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    cout << c(n - 2, m - 1) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}