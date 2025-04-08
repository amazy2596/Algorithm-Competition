#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e6 + 5;
const int mod = 998244353;
int fact[N], ifact[N], p[N], f[N];

int fast_pow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        
        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

void init()
{
    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = (p[i - 1] * 2) % mod;

    f[1] = f[2] = 1;
    for (int i = 3; i < N; i++)
        f[i] = (f[i - 1] + f[i - 2]) % mod;

    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    
    ifact[N - 1] = fast_pow(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--)
        ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
}

int C(int n, int m)
{
    if (n < m)
        return 0;
    return (fact[n] % mod * ifact[m] % mod * ifact[n - m] % mod) % mod;
}

int A(int n, int m)
{
    if (n < m)
        return 0;
    return (fact[n] % mod * ifact[n - m] % mod) % mod;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++)
    {
        x[n - i + 1] = (x[n - i + 1] + a[i]) % mod;
        y[i] = (y[i] + a[i]) % mod;
    }

    for (int i = n - 1; i >= 1; i--)
    {
        x[i] = (x[i] + x[i + 1]) % mod;
        y[i] = (y[i] + y[i + 1]) % mod;
    }

    int ans = x[1] % mod;
    for (int i = 2; i <= n; i++)
        ans = (ans + x[i] * f[i - 2] % mod + y[i] * f[i - 1]) % mod;

    cout << ans % mod << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}