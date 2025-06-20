#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e6 + 5;
const int mod = INT64_MAX;
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
    s = " " + s;
    vector<int> pre(n + 1);
    int pos1 = 0, pos2 = 0;
    int tot1 = 0, tot2 = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + (s[i] == '1' ? 1 : -1);
        
        if (pos1 == 0)
            tot1 += (s[i] == '0');
        else if (pos2 == 0)
            tot2 += (s[i] == '0');

        if (pre[i] == -1 && pos1 == 0)
        {
            pos1 = i;
            pre[i] = 1;
        }

        if (pre[i] == -1 && pos2 == 0)
        {
            pos2 = i;
            pre[i] = 1;
        }

        if (pre[i] == -1 && pos1 != 0 && pos2 != 0)
        {
            cout << "0\n";
            return;
        }
    }

    if (pos1 == 0)
        cout << n * (n - 1) / 2;
    else if (pos2 == 0)
        cout << tot1 * (tot1 - 1) / 2 + tot1 * (n - tot1);
    else 
        cout << tot1 * (tot1 - 1) / 2 + tot1 * tot2;

}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}