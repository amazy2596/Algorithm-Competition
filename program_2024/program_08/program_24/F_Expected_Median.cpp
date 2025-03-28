#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int fact[N + 5], ifact[N + 5];

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
    return res % mod;
}

int c(int n, int m)
{
    if (n < m)
        return 0ll;
    // return (fact[n] * fast_pow((fact[n - m] * fact[m]) % mod, mod - 2) % mod) % mod;
    return (fact[n] * ifact[n - m]) % mod * ifact[m] % mod;
}

void init()
{   
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    ifact[N] = fast_pow(fact[N], mod - 2);
    // cout << ifact[N] << " ";
    for (int i = N - 1; i >= 0; i--)
    // {
        ifact[i] = ifact[i + 1] * (i + 1) % mod;
        // cout << ifact[i] << " ";
    // }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        one += x;
    }
    int ans = 0;
    for (int m = k / 2 + 1; m <= min(k, one); m++)
    {
        int a = c(one, m);
        int b = c(n - one, k - m);
        ans += (a * b) % mod;
        ans %= mod;
    }
    cout << ans % mod << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    init();
    while (T--)
        solve();
    return 0;
}