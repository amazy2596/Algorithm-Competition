#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct DSU
{
    vector<int> f, siz;

    DSU(int n) : f(n + 1), siz(n + 1, 1)
    {
        iota(f.begin(), f.end(), 0);
    }

    int find(int x)
    {
        while (f[x] != x)
            x = f[x] = f[f[x]];
        return x;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (siz[x] < siz[y])
            swap(x, y);

        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

const int mod1 = 1000000007;
const int mod2 = 998244353;
const int mod = mod2;
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
    vector<int> a(n + 1);
    DSU dsu(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dsu.merge(i, a[i]);
    }

    map<int, int> mp;
    for (int i = 1; i <= n; i++)
        mp[dsu.find(i)]++;

    int odd = 0;
    for (auto [key, val] : mp)
    {
        if (val % 2 == 1)
            odd++;
    }

    if (odd != 0 && odd != 2)
    {
        cout << "0\n";
        return;
    }

    int ans = 0;
    if (odd == 2)
    {
        int tmp = 1;
        set<int> toearse;
        for (auto [key, val] : mp)
        {
            if (val % 2 == 1)
                tmp *= val;
            if (val == 2)       
                toearse.insert(key);
        }
        for (auto x : toearse)
            mp.erase(x);

        ans = tmp * comb.fast_pow(2, mp.size() - 2) % mod;
    }
    else 
    {
        int cnt = 0;
        for (auto [key, val] : mp)
        {
            if (val == 2)       
                cnt++;
        }

        int even = mp.size();
        for (auto [key, val] : mp)
        {
            if (val == 2)
                ans = (ans + comb.fast_pow(2, even - cnt)) % mod;
            else 
                ans = (ans + (val * val / 4) % mod * comb.fast_pow(2, even - 1 - cnt)) % mod;
            
        }
    }

    cout << ans % mod << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}