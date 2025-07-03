#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int N = 1e6 + 5;
const int mod = 1000000007;
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

    int k = n;

    n %= (mod - 1);

    string s;
    cin >> s;
    int m = s.length();
    s = " " + s;

    vector<int> cnt(2, 0);
    for (int i = 1; i <= m; i++)
        cnt[s[i] - '0']++;

    vector<int> pre(m + 1), suf(m + 2);
    for (int i = 1; i <= m; i++)
        pre[i] = pre[i - 1] + (s[i] == '0');
    for (int i = m; i >= 1; i--)
        suf[i] = suf[i + 1] + (s[i] == '1');

    int diff = cnt[0] - cnt[1];
    int gb;
    if (diff >= 0)
        gb = fast_pow(2, diff);
    else 
        gb = fast_pow(fast_pow(2, -diff), mod - 2);

    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (s[i] == '0')
        {
            int a = fast_pow(2, (pre[i - 1] + suf[i + 1] + ((k - 1) % (mod - 1) * cnt[1]) % (mod - 1)) % (mod - 1));
            int b;
            if (gb == 1)
                b = k;
            else 
                b = (((fast_pow(gb, n) - 1 + mod) % mod) * fast_pow((gb - 1 + mod) % mod, mod - 2)) % mod;
            ans = (ans + (a % mod) * (b % mod)) % mod;
        }
    }

    ans = (ans + fast_pow(2, (n * cnt[1]) % (mod - 1))) % mod;

    cout << (ans - 1 + mod) % mod << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}