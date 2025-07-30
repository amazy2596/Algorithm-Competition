#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int P = 998244353, G = 3;
int fast_pow(int a, int b, int mod)
{
    int res = 1;
    a %= mod;
    while (b) 
    {
        if (b & 1)
            res = (1LL * res * a) % mod;

        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}

int inv(int x, int mod) 
{
    return fast_pow(x, mod - 2, mod);
}

struct NTT 
{
    int mod, g;
    vector<int> rev;
    vector<int> roots;

    NTT(int _mod, int _g = 3) : mod(_mod), g(_g) 
    {
        roots = {0, 1};
    }

    void dft(vector<int> &a) 
    {
        int n = a.size();
        if (rev.size() != n) 
        {
            int k = __builtin_ctz(n) - 1;
            rev.resize(n);
            for (int i = 0; i < n; i++)
                rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
        }
        for (int i = 0; i < n; i++) 
            if (rev[i] < i) 
                swap(a[i], a[rev[i]]);

        if (roots.size() < n) 
        {
            int k = __builtin_ctz(roots.size());
            roots.resize(n);
            while ((1 << k) < n) 
            {
                int e = fast_pow(g, (mod - 1) / (1ll << (k + 1)), mod);
                for (int i = 1 << (k - 1); i < (1 << k); i++) 
                {
                    roots[2 * i] = roots[i];
                    roots[2 * i + 1] = 1LL * roots[i] * e % mod;
                }
                k++;
            }
        }

        for (int len = 2; len <= n; len <<= 1) 
        {
            for (int i = 0; i < n; i += len) 
            {
                for (int j = 0; j < len / 2; j++) 
                {
                    int u = a[i + j];
                    int v = (1LL * roots[j + len / 2] * a[i + j + len / 2]) % mod;
                    a[i + j] = (u + v) % mod;
                    a[i + j + len / 2] = (u - v + mod) % mod;
                }
            }
        }

    }

    void idft(vector<int> &a)
    {
        int n = a.size();
        reverse(a.begin() + 1, a.end());
        dft(a);
        int tmp = inv(n, mod);
        for (int i = 0; i < n; i++)
            a[i] = (1LL * a[i] * tmp) % mod;
    }

    vector<int> mul(const vector<int> &a, const vector<int> &b) 
    {
        int tot = a.size() + b.size() - 1;
        if (tot <= 0) return {};

        if (tot < 128) 
        {
            vector<int> res(tot, 0);
            for (int i = 0; i < a.size(); i++) 
            {
                for (int j = 0; j < b.size(); j++) 
                {
                    res[i + j] =(res[i + j] + ((a[i] * b[j]) % mod)) % mod;
                }
            }
            return res;
        }

        int n = 1;
        while (n < tot) n <<= 1;

        vector<int> fa(a); fa.resize(n);
        vector<int> fb(b); fb.resize(n);

        dft(fa);
        dft(fb);

        for (int i = 0; i < n; i++)
            fa[i] = (1LL * fa[i] * fb[i]) % mod;

        idft(fa);
        fa.resize(tot);
        return fa;
    }
} ntt(P, G);

void solve()
{
    
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