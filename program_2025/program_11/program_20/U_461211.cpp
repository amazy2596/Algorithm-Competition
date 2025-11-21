// Problem: 字符串 Hash（数据加强）
// URL: https://www.luogu.com.cn/problem/U461211
// Author: amazy
// Date: 2025-11-20 22:06:50

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

using u64 = uint64_t;
using u128 = __uint128_t;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct StringHash 
{
    static constexpr u64 MOD  = (1ull << 61) - 1;
    inline static u64 BASE = uniform_int_distribution<u64>(MOD / 2, MOD - 2)(rng);
    inline static vector<u64> P{1};
    inline static int max_pow = 0;

    struct Hash 
    {
        u64 val = 0;
        int len = 0;
        Hash() = default;
        Hash(u64 v, int l): val(v), len(l) {}
        auto operator<=>(const Hash&) const = default;
        Hash operator+(const Hash &rhs) const {
            ensure(rhs.len);
            return Hash(add(mul(val, P[rhs.len]), rhs.val), len + rhs.len);
        }
    };

    vector<u64> h;
    StringHash() = default;
    StringHash(const string &s) { build(s); }

    void build(const string &s) 
    {
        int n = s.size();
        ensure(n);
        h.assign(n + 1, 0);
        for (int i = 0; i < n; i++) 
        {
            h[i + 1] = add(mul(h[i], BASE), s[i]);
        }
    }

    Hash query(int l, int r)
    {
        if (r < l) return Hash(0, 0);
        int len = r - l + 1;
        ensure(len);
        u64 val = sub(h[r + 1], mul(h[l], P[len]));
        return Hash(val, len);
    }

    Hash whole() { return Hash(h.back(), h.size() - 1); }
    
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
    unordered_map<u64, int> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        StringHash sh(s);
        auto h = sh.whole();
        mp[h.val]++;
    }
    cout << mp.size() << "\n";
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