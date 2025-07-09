#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int N = 1e6 + 5;
const int mod1 = 1000000007; 
const int mod2 = 998244353;
const int mod = mod2;
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

vector<vector<int>> matrix_mul(vector<vector<int>> a, vector<vector<int>> b)
{
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
                res[i][j] += a[i][k] * b[k][j], res[i][j] %= mod;
        }
    }
    
    return res;
}

vector<vector<int>> matrix_pow(vector<vector<int>> a, int b)
{
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    while (b)
    {
        if (b & 1)
            res = matrix_mul(res, a);
        a = matrix_mul(a, a);
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

int inv(int x)
{
    return fast_pow(x, mod - 2);
}

int C(int n, int m)
{
    if (n < m)
        return 0;
    if (n < N && m < N)
        return (fact[n] % mod * ifact[m] % mod * ifact[n - m] % mod) % mod;
    
    int res = ifact[m];
    for (int i = 1; i <= m; i++)
        res = (res * ((n - m + i) % mod + mod)) % mod;

    return res;
}

int A(int n, int m)
{
    if (n < m)
        return 0;
    if (n < N && m < N)
        return (fact[n] % mod * ifact[n - m] % mod) % mod;

    int res = 1;
    for (int i = 1; i <= m; i++)
        res = (res * ((n - m + i) % mod + mod)) % mod;

    return res;
}

void solve()
{
    int n;
    cin >> n;

    int ans = 0;
    ans = (ans + 49 * (n % mod)) % mod;
    ans = (ans + (28 * ((fast_pow(10, n + 1) - 10 + mod) % mod) % mod) * inv(9)) % mod;
    ans = (ans + (4 * ((fast_pow(10, 2 * n + 2) - 100 + mod) % mod) % mod) * inv(99)) % mod;
    ans = (ans * inv(81)) % mod;

    cout << ans % mod << "\n";
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