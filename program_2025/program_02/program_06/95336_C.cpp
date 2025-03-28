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
    cin >> n;
    string s;
    cin >> s;
    if (n == 1)
    {
        if (s[0] == '?')
            cout << 2 << "\n";
        else 
            cout << 1 << "\n";
        return;
    }
    int ans = 0;
    int cnt = 0;
    for (int i = 1; i < s.length() - 1; i++)
        cnt += (s[i] == '?');
    vector<int> a, b;
    if (s[0] == '1')
        a = {1};
    else if (s[0] == '0')
        a = {0};
    else 
        a = {1, 0};
    
    if (s[n - 1] == '1')
        b = {1};
    else if (s[n - 1] == '0')
        b = {0};
    else 
        b = {1, 0};

    int same_1 = 0, same_0 = 0;
    for (auto aa : a)
    {
        for (auto bb : b)
        {
            if (aa + bb == 1)
                same_1++;
            else 
                same_0++;
        }
    }

    ans = (ans + p[cnt] * same_1 * 2) % mod;
    ans = (ans + p[cnt] * same_0 * (n - 2)) % mod;

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    init();
    cin >> T;
    while (T--)
        solve();
    return 0;
}