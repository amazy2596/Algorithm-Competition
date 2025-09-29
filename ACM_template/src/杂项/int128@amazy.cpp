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

ostream &operator<<(ostream &os, i128 n) 
{
    if (n == 0) return os << 0;
    string s;
    while (n > 0) 
    {
        s += char('0' + n % 10);
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}
 
i128 toi128(const string &s) 
{
    i128 n = 0;
    for (auto c : s)
        n = n * 10 + (c - '0');
    return n;
}
 
i128 sqrti128(i128 n) 
{
    i128 lo = 0, hi = 1E16;
    while (lo < hi) 
    {
        i128 x = (lo + hi + 1) / 2;
        if (x * x <= n) 
            lo = x;
        else
            hi = x - 1;
    }
    return lo;
}

i128 gcd(i128 a, i128 b) 
{
    while (b) 
    {
        a %= b;
        swap(a, b);
    }
    return a;
}