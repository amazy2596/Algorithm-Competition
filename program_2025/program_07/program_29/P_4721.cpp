#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int mod = 998244353;
int fast_pow(int a, int b) 
{
    int res = 1;
    a %= mod;
    while (b) 
    {
        if (b & 1)
            res = (res * a) % mod;

        a = (1ll * a * a) % mod;
        b >>= 1;
    }
    return res;
}

int inv(int x) 
{
    return fast_pow(x, mod - 2);
}

vector<int> rev, roots {0, 1};
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
    {
        if (rev[i] < i) 
        {
            swap(a[i], a[rev[i]]);
        }
    }
    if (roots.size() < n) 
    {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) 
        {
            int e = fast_pow(31, 1 << (__builtin_ctz(mod - 1) - k - 1));
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
                int u = a[i + j] % mod;
                int v = (roots[j + len / 2] * a[i + j + len / 2]) % mod;

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
    int tmp = (1 - mod) / n;
    for (int i = 0; i < n; i++)
        a[i] = 1LL * a[i] * tmp % mod;
}

vector<int> mul(vector<int> &a, vector<int> &b)
{
    int n = 1, tot = a.size() + b.size() - 1;
    while (n < tot)
        n <<= 1;

    if (tot < 128)
    {
        vector<int> c(a.size() + b.size() - 1);
        for (int i = 0; i < a.size(); i++) 
        {
            for (int j = 0; j < b.size(); j++) 
            {
                c[i + j] = (c[i + j] + 1LL * a[i] * b[j]) % mod;
            }
        }
        return c;
    }

    a.resize(n);
    b.resize(n);

    dft(a);
    dft(b);

    for (int i = 0; i < n; i++)
        a[i] = (1ll * a[i] * b[i]) % mod;

    idft(a);
    a.resize(tot);

    return a;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> g(n), f(n);
    for (int i = 1; i < n; i++)
        cin >> g[i];
    f[0] = 1;
    
    auto calc = [&](auto calc, int l, int r, bool invert) -> void
    {
        if (l == r) return;

        int mid = (l + r) / 2;
        calc(calc, l, mid, invert);
        calc(calc, mid + 1, r, invert);


    };
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