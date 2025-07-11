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
    vector<int> cnt(4, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int ans = 1;
    int A = cnt[1], B = cnt[2], C = cnt[3];
    int pow2A = comb.fast_pow(2, A);
    int S2 = 0, S3 = 0;
    for (int b = 0; b <= B; b++)
    {
        int tmp = 1;
        tmp = (tmp * (b + 1)) % mod;
        tmp = (tmp * comb.C(B, b)) % mod;
        S2 = (S2 + tmp) % mod;
    }
    
    for (int c = 0; c <= C; c++)    
    {
        int tmp = 1;
        tmp = (tmp * (c + 1)) % mod;
        tmp = (tmp * comb.C(C, c)) % mod;
        S3 = (S3 + tmp) % mod;
    }

    ans = (ans * pow2A) % mod;
    ans = (ans * S2) % mod;
    ans = (ans * S3) % mod; 

    cout << (ans - 1 + mod) % mod << "\n";
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