#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1000000007;
const int N = 1e7 + 5;
int fact[N], ifact[N];

int fast_pow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

void init()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    ifact[N - 1] = fast_pow(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--)
        ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
}

int c(int n, int m)
{
    if (n < m)
        return 0;
    return (fact[n] % mod * ifact[m] % mod * ifact[n - m] % mod) % mod;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k < 2 || n % 2 == 1)
        cout << 0 << '\n';
    else
    {
        if (k > n / 2)
            cout << c(n, k) % mod << "\n";
        else
            cout << (c(n, k) - (c(n / 2, k) % mod * fast_pow(2, k) % mod) % mod + mod) % mod << "\n";
    }
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