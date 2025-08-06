#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

const long double eps = 1e-12;
const i64 inf = 1e18; 

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };

const int mod = 998244353;
i64 fast_pow(i64 a, i64 b) 
{
    i64 res = 1;
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

i64 inv(i64 x) 
{
    return fast_pow(x, mod - 2);
}

struct FWT
{
    FWT() {}

    template<typename T>
    void OR(vector<T> &a, int type)
    {
        int n = a.size();
        for (int len = 2; len <= n; len <<= 1)
        {
            int step = len / 2;
            for (int i = 0; i < n; i += len)
            {
                for (int j = 0; j < step; j++)
                {
                    a[i + j + step] = (a[i + j + step] + type * a[i + j] + mod) % mod;
                }
            }
        }
    }

    template<typename T>
    void AND(vector<T> &a, int type)
    {
        int n = a.size();
        for (int len = 2; len <= n; len <<= 1)
        {
            int step = len / 2;
            for (int i = 0; i < n; i += len)
            {
                for (int j = step - 1; j >= 0; j--)
                {
                    a[i + j] = (a[i + j] + type * a[i + j + step] + mod) % mod;
                }
            }
        }
    }

    template<typename T>
    void XOR(vector<T> &a, int type)
    {
        int n = a.size();
        for (int len = 2; len <= n; len <<= 1)
        {
            int step = len / 2;
            for (int i = 0; i < n; i += len)
            {
                for (int j = 0; j < step; j++)
                {
                    T u = a[i + j];
                    T v = a[i + j + step];

                    a[i + j] = (u + v) % mod;
                    a[i + j + step] = ((u - v) % mod + mod) % mod;
                }
            }
        }

        if (type == -1)
        {
            T invN = inv(n);
            for (auto &x : a) 
            {
                x = (x * invN) % mod;
            }
        }
    }

    using Func = function<vector<i64>(vector<i64>&, int)>;
    template<typename T>
    vector<T> work(const vector<T> &a, const vector<T> &b, Func op)
    {
        int tot = a.size() + b.size() - 1;
        if (tot <= 0) return {};
        int n = 1;
        while (n < tot) n <<= 1;

        vector<T> fa(a);
        vector<T> fb(b);

        fa.resize(n);
        fb.resize(n);

        op(fa, 1);
        op(fb, 1);

        for (int i = 0; i < n; i++)
            fa[i] = (fa[i] * fb[i]) % mod;

        op(fa, -1);
        fa.resize(tot);
        return fa;
    }
} fwt;

struct Comb 
{
    int max_n;          
    vector<int> fact; 
    vector<int> ifact;

    Comb() : max_n(0)
    {
        fact.push_back(1);
        ifact.push_back(1);
    }

    Comb(int n) : max_n(n)
    {
        extend_to(n);
    }

    void extend_to(int new_max_n)
    {
        if (new_max_n <= max_n) return;

        int old_max_n = max_n;
        max_n = new_max_n;

        fact.resize(max_n + 1);
        ifact.resize(max_n + 1);

        for (int i = old_max_n + 1; i <= max_n; i++)
            fact[i] = (1LL * fact[i - 1] * i) % mod;
        
        ifact[max_n] = fast_pow(fact[max_n], mod - 2);
        for (int i = max_n - 1; i > old_max_n; i--)
            ifact[i] = (1LL * ifact[i + 1] * (i + 1)) % mod;
    }

    int fast_pow(int a, int b) 
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

    int inv(int x) 
    {
        if (x > max_n) extend_to(x);
        return fast_pow(x, mod - 2);
    }
    
    int C(int n, int m) 
    {
        if (n < m || m < 0) return 0;
        
        if (n > max_n)
            extend_to(2 * n); 

        return (((1LL * fact[n] * ifact[m]) % mod) * ifact[n - m]) % mod;
    }

    int A(int n, int m) 
    {
        if (n < m || m < 0) return 0;
        
        if (n > max_n)
            extend_to(2 * n);
        
        return (1LL * fact[n] * ifact[n - m]) % mod;
    }
} Comb;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    unordered_map<int, int> special;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        special.insert({x, i});
    }

    vector<pair<int, int>> roads(k);
    for (int i = 0; i < k; i++)
    {
        int s, t;
        cin >> s >> t;
        roads.emplace_back(s, t);
    }

    vector<int> node_masks(n + 1);
    auto dfs = [&](auto dfs, int u, int p, int mask) -> void
    {
        node_masks[u] = mask;

        for (auto [v, id] : adj[u])
        {
            if (v == p)
                continue;

            int tmp = mask;
            if (special.find(id) != special.end())
                tmp ^= (1ll << special[id]);

            dfs(dfs, v, u, tmp);
        }
    };
    dfs(dfs, 1, 0, 0);

    int all = 0;
    vector<i64> count(1LL << m);
    for (auto [s, t] : roads)
    {
        int mask = node_masks[s] ^ node_masks[t];
        count[mask]++;
        all |= mask;
    }

    if (all != (1LL << m) - 1)
    {
        cout << "-1\n";
        return;
    }

    fwt.OR(count, 1);

    for (int i = 1; i <= m; i++)
    {
        int ans = 0;
        for (int mask = 0; mask < (1LL << m); mask++)
        {
            int num = count[mask];
            int cnt = Comb.C(num, i);

            if ((m - __builtin_popcount(mask)) % 2 == 0)
                ans = (ans + cnt) % mod;
            else 
                ans = (ans - cnt + mod) % mod;
        }

        if (ans > 0)
        {
            cout << i << " " << ans << "\n";
            return;
        }
    }

    cout << "-1\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}