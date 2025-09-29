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

struct Matrix 
{
    int n, m;
    vector<i64> mt;

    Matrix() {}
    Matrix(int _n, int _m): n(_n), m(_m) { mt.resize(n * m, 0LL); }
    Matrix(initializer_list<initializer_list<i64>> init) : n(init.size()), m(init.begin()->size()), mt(1LL * n * m, 0)
    {
        int i = 0;
        for (auto &row : init) 
        {
            for (auto x : row)
                mt[i++] = (x % mod + mod) % mod;
        }
    }

    static Matrix identity(int n)
    {
        Matrix I(n, n);
        for (int i = 0; i < n; i++) I[i][i] = 1;
        return I;
    }

    i64* operator[](int i) { return mt.data() + 1LL * i * m; }
    const i64* operator[](int i) const { return mt.data() + 1LL * i * m; }

    friend Matrix operator*(const Matrix &l, const Matrix &r) 
    {
        assert(l.m == r.n);
        Matrix res(l.n, r.m);
        for (int i = 0; i < l.n; i++) 
        {
            for (int k = 0; k < l.m; k++) 
            {
                if (l[i][k] == 0) continue;
                for (int j = 0; j < r.m; j++) 
                {
                    res[i][j] = (res[i][j] + (i128)l[i][k] * r[k][j]) % mod;
                }
            }
        }
        return res;
    }

    friend ostream& operator<<(ostream &os, const Matrix &o) 
    {
        for(int i = 0; i < o.n; ++i) 
        {
            for(int j = 0; j < o.m; ++j) 
            {
                os << o[i][j] << " \n"[j == o.m - 1];
            }
        }
        return os;
    }
};

Matrix fast_pow(Matrix base, i64 b) 
{
    assert(base.n == base.m);
    Matrix res = Matrix::identity(base.n);
    while (b) 
    {
        if (b & 1) res = res * base;
        base = base * base;
        b >>= 1;
    }
    return res;
}