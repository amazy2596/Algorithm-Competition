// Problem: 【模板】字符串哈希
// URL: https://www.luogu.com.cn/problem/P3370
// Author: amazy
// Date: 2025-09-02 01:02:14

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

struct StringHash 
{
    static constexpr u64 MOD  = (1ull << 61) - 1;
    inline static u64 BASE = rnd(MOD / 2, MOD - 2);
    inline static vector<u64> P{1};
    inline static int max_pow = 0;

    struct Hash 
    {
        u64 val = 0;
        int len = 0;
        Hash() = default;
        Hash(u64 v, int l): val(v), len(l) {}

        Hash operator+(const Hash& rhs) const 
        {
            ensure(rhs.len);
            return Hash(add(rhs.val, mul(val, P[rhs.len])), len + rhs.len);
        }

        bool operator==(const Hash &o) const 
        { 
            return val == o.val && len == o.len; 
        }
        bool operator<(const Hash &o) const 
        {
            return (val < o.val) || (val == o.val && len < o.len);
        }
    };

    vector<u64> h;
    StringHash() = default;
    StringHash(const string &s) { build(s); }

    void build(const string &s) 
    {
        int n = s.size();
        ensure(n);
        h.assign(n + 1, 0ull);
        for (int i = 1; i <= n; ++i) 
        {
            u64 v = (u64)(unsigned char)s[i - 1] + 1ull;
            h[i] = add(mul(h[i - 1], BASE), v);
        }
    }

    Hash query(int l, int r)
    {
        if (r < l) return Hash(0, 0);
        int m = r - l + 1;
        ensure(m);
        return Hash(sub(h[r + 1], mul(h[l], P[m])), m);
    }

    Hash whole() 
    { 
        return Hash(h.back(), h.size() - 1); 
    }

    static u64 add(u64 a, u64 b) 
    {
         a += b; 
         if (a >= MOD) a -= MOD; 
         return a; 
    }
    static u64 sub(u64 a, u64 b) 
    { 
        return a >= b ? (a - b) : (a + MOD - b); 
    }
    static u64 mul(u64 a, u64 b) 
    {
        u128 c = (u128)a * b;
        u64 res = (u64)(c >> 61) + (u64)(c & MOD);
        if (res >= MOD) res -= MOD;
        return res;
    }
    static void ensure(int m) 
    {
        if (max_pow >= m) return;
        P.resize(m + 1);
        for (int i = max_pow + 1; i <= m; ++i) P[i] = mul(P[i - 1], BASE);
        max_pow = m;
    }
};

void solve()
{
    int n;
    cin >> n;
    set<StringHash::Hash> s;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        s.insert(StringHash(t).whole());
    }

    cout << s.size() << "\n";
}

int main()
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