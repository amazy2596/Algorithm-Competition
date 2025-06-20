#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
const int N = 2e6 + 5;
// int fact[N], ifact[N];

// int fast_pow(int a, int b)
// {
//     int res = 1;
//     while (b)
//     {
//         if (b & 1)
//             res = res * a % mod;
//         b >>= 1;
//         a = (a * a % mod) % mod;
//     }
//     return res;
// }

// void init()
// {
//     fact[0] = 1;
//     for (int i = 1; i < N; i++)
//         fact[i] = (i * fact[i - 1]) % mod;
//     ifact[N - 1] = fast_pow(fact[N - 1], mod - 2);
//     for (int i = N - 2; i >= 0; i--)
//         ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
// }

// int c(int n, int m)
// {
//     return (fact[n] % mod * (ifact[n - m] % mod * ifact[m] % mod)) % mod;
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> ar(n + 1);
//     for (int v = 2; v <= n; v++)
//     {
//         int u;
//         cin >> u;
//         ar[u].push_back(v);
//     }
//     int a = 0, b = d0;
//     for (int i = 1; di <= n - 1; i++)
//         b += c(n - 1, i) % mod;
//     for (int i = 0; i <= n; i++)
//         a += c(n, i) % mod;
//     cout << (a - b + mod) % mod << "\n";
// }

int f[N][2];
vector<int> a[N];

void dfs(int u)
{
    f[u][0] = f[u][1] = 1;
    for (int v : a[u])
    {
        dfs(v);
        f[u][0] *= (f[v][0] + f[v][1]) % mod;
        f[u][0] %= mod;
        f[u][1] *= f[v][0] % mod;
        f[u][1] %= mod;
        // cout << "f[u][0]: " << f[u][0] << " " << "f[u][1]: " << f[u][1] << "\n";
    }
}

void solve()
{
    int n;
    cin >> n; 
    for (int v = 2; v <= n; v++)
    {
        int u;
        cin >> u;
        a[u].push_back(v);
    }
    dfs(1);
    cout << (f[1][0] + f[1][1]) % mod << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
