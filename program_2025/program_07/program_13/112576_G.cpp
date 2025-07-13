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

const int mod1 = 1000000007;
const int mod2 = 998244353;
const int mod = mod1;

struct Comb 
{
    int max_n;          
    vector<int> fact; 
    vector<int> ifact; 
    vector<int> p2;

    Comb(int n = 2e6 + 5) : max_n(n)
    {
        fact.resize(max_n + 1);
        ifact.resize(max_n + 1);
        p2.resize(max_n + 1);

        p2[0] = 1;
        for (int i = 1; i <= max_n; i++) p2[i] = (p2[i - 1] * 2) % mod;

        fact[0] = 1;
        for (int i = 1; i <= max_n; i++) fact[i] = (fact[i - 1] * i) % mod;
        
        ifact[max_n] = fast_pow(fact[max_n], mod - 2);
        for (int i = max_n - 1; i >= 0; i--) ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
    }

    int fast_pow(int a, int b) 
    {
        int res = 1;
        a %= mod;
        while (b) 
        {
            if (b & 1)
                 res = (res * a) % mod;

            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    int inv(int x) 
    {
        return fast_pow(x, mod - 2);
    }

    int C(int n, int m) 
    {
        if (n < m || m < 0) return 0;
        if (n <= max_n) return (((fact[n] * ifact[m]) % mod) * ifact[n - m]) % mod;

        int res = ifact[m];
        for (int i = 1; i <= m; i++) res = (res * ((n - m + i))) % mod;

        return res;
    }

    int A(int n, int m) 
    {
        if (n < m || m < 0) return 0;
        if (n <= max_n) return (fact[n] * ifact[n - m]) % mod;
        
        int res = 1;
        for (int i = 1; i <= m; i++) res = (res * (n - m + i)) % mod;
        return res;
    }
} comb;

void solve()
{
    int n;
    cin >> n;
    vector<int> b(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> b[i];

    sort(b.begin(), b.end());

    vector<vector<int>> dp(105, vector<int>(n + 1));
    // dp[i] = 1 + q * dp[i + 1] + p * dp[i - 1];
    // dp[i + 1] = (dp[i] - p * dp[i - 1] - 1) / q;
    // dp[0] = 1 / q + dp[1];
    // dp[1] = dp[0] - 1 / q;
    int inv100 = comb.fast_pow(100, mod - 2);
    for (int i = 1; i <= 100; i++)
    {
        int q = i * inv100 % mod;
        int p = (100 - i) * inv100 % mod;
        int inv_q = comb.fast_pow(q, mod - 2);

        vector<int> A(n + 1), B(n + 1);
        A[0] = 1, A[1] = 1, B[1] = mod - inv_q;
        for (int j = 2; j <= n; j++)
        {
            A[j] = ((((A[j - 1] - (A[j - 2] * p) % mod) + mod) % mod) * inv_q) % mod;
            B[j] = ((((B[j - 1] - (B[j - 2] * p) - 1) % mod) + mod) * inv_q) % mod;
        }

        int dp0 = ((mod - B[n]) * comb.fast_pow(A[n], mod - 2)) % mod;
        for (int j = 0; j <= n; j++)
            dp[i][j] = (A[j] * dp0 + B[j] + mod) % mod;
    }

    vector<int> a;
    for (int i = 1; i <= n; i++)
    {
        a.push_back(i);
        a.push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < 2 * n; i++)
        ans = (ans + (dp[b[i]][0] - dp[b[i]][a[i]] + mod) % mod) % mod;

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}