#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int fact[N], ifact[N], p[N];

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
    string s;
    cin >> n >> s;
    reverse(s.begin(), s.end());
    s = " " + s;

    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++)
        f[i] = (s[i] == '1' ? (f[i - 1] + fast_pow(2, mod - 2) * ((1 - f[i - 1] + mod) % mod)) % mod 
        : (fast_pow(2, mod - 2) * f[i - 1]) % mod);

    cout << (n - 1 + f[n - 1]) % mod << "\n";
}

signed main()
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