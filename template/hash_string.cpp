#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const uint mod = (1ull << 61) - 1;
const uint base = rnd(mod / 2, mod - 1);
const int N = 2e5 + 5;
vector<uint> p(N);

uint add(uint a, uint b)
{
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

uint mul(uint a, uint b)
{
    __uint128_t c = __uint128_t(a) * b;
    return add(c >> 61, c & mod);
}

uint query(const vector<uint> &h, int l, int r)
{
    if (r < l)
        return 0ull;
    return add(h[r], mod - mul(h[l - 1], p[r - l + 1]));
}

void init()
{
    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = mul(p[i - 1], base);
}

template<typename T>
vector<uint> build(vector<T> &s)
{
    vector<uint> hashed(s.size(), 0);
    for (int i = 1; i < s.size(); i++)
        hashed[i] = add(mul(hashed[i - 1], base), s[i]);
    return hashed;
}

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