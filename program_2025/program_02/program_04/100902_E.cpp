#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int fact[N], ifact[N];

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
    int cnt = n / 3;

    if (n == 2)
    {
        cout << 0 << "\n";
        return;
    }

    int ans = 1;
    // cout << cnt << " " << n / 2 << "\n";
    if (cnt * 2 == n / 2)
    {
        ans = (ans * A(n - cnt, cnt)) % mod;
        ans = (ans * A(n - cnt, n - cnt)) % mod;
        cout << ans << "\n";
    }
    else 
    {
        int repeat = cnt * 2 - n / 2;
        ans = (ans * C(cnt, repeat)) % mod;
        ans = (ans * A(cnt, repeat)) % mod;
        ans = (ans * A(n - cnt, cnt - repeat)) % mod;
        ans = (ans * A(n - cnt, n - cnt)) % mod;
        cout << ans << "\n";
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    init();
    // cin >> T;
    while (T--)
        solve();
    return 0;
}