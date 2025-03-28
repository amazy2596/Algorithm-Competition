#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e5 + 5;
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
    vector<string> g(3);
    for (int i = 0; i < 3; i++)
        cin >> g[i];

    vector<map<char, int>> mp(3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == '?')
                continue;
            mp[j % 3][g[i][j]]++;
        }
    }

    if (mp[0].size() > 3 || mp[1].size() > 3 || mp[2].size() > 3)
    {
        cout << 0 << "\n";
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        for (auto [key1, val1] : mp[i])
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j)
                    continue;
                for (auto [key2, val2] : mp[j])
                {
                    if (mp[i].find(key2) != mp[i].end())
                    {
                        cout << 0 << "\n";
                        return;
                    }
                }
            }
        }
    }

    for (int j = 0; j < n; j++)
    {
        vector<int> vis(10);
        for (int i = 0; i < 3; i++)
        {
            if (g[i][j] == '?')
                continue;
            if (vis[g[i][j] - '0'])
            {
                cout << 0 << "\n";
                return;
            }
            vis[g[i][j] - '0'] = 1;
        }
    }

    int num = 0;
    vector<int> f(n), ne(3);
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (g[i][j] == '?')
                f[j]++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        ne[i] = 3 - mp[i].size();
        num += 3 - mp[i].size();
    }

    int ans = 1;
    ans = ans * C(num, ne[0]) % mod;
    ans = ans * C(num - ne[0], ne[1]) % mod;
    ans = ans * C(num - ne[0] - ne[1], ne[2]) % mod;
    for (int i = 0; i < n; i++)
        ans = ans * A(f[i], f[i]) % mod;

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