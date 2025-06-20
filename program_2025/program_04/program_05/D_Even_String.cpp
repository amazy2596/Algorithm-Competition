#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e6 + 5;
const int mod = 998244353;
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
    int N = 26;
    vector<int> a(N + 1);
    int n = 0, cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        n += a[i];
        cnt += (a[i] != 0);
    }

    int o = (n + 1) / 2;
    vector dp(N + 1, vector<int>(o + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= o; j++)
        {
            dp[i][j] = dp[i - 1][j] % mod;
            if (a[i] > 0 && j >= a[i])
                dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % mod;
        }
    }

    int ans = dp[N][o] * fact[o] % mod * fact[n - o] % mod % mod;
    for (int i = 1; i <= N; i++)
        ans = (ans * ifact[a[i]]) % mod;

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