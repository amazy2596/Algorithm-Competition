#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

const i64 mod = 1e9 + 7;
struct Matrix 
{
    int n, m;
    vector<i64> mt;

    Matrix() {}
    Matrix(int _n, int _m) : n(_n), m(_m), mt(n * m, 0) {}
    Matrix(int _n, int _m, i64 val) : n(_n), m(_m), mt(n * m, val) {}
    Matrix(initializer_list<initializer_list<i64>> init) : n(init.size()), m(init.begin()->size()), mt(1LL * n * m, 0)
    {
        int i = 0;
        for (auto &row : init) 
        {
            for (auto x : row)
            {
                mt[i++] = (x % mod + mod) % mod;
            }
        }
    }

    i64* operator[](int i) { return mt.data() + i * m; }
    const i64* operator[](int i) const { return mt.data() + i * m; }

    static Matrix identity(int n) 
    {
        Matrix res(n, n);
        for (int i = 0; i < n; i++) res[i][i] = 1;
        return res;
    }

    friend Matrix operator+(const Matrix &a, const Matrix &b) 
    {
        assert(a.n == b.n && a.m == b.m);
        Matrix res(a.n, a.m);
        for (int i = 0; i < a.n * a.m; i++) 
        {
            res.mt[i] = (a.mt[i] + b.mt[i]) % mod;
        }
        return res;
    }

    friend Matrix operator*(const Matrix &a, const Matrix &b) 
    {
        assert(a.m == b.n);
        Matrix res(a.n, b.m);
        for (int i = 0; i < a.n; i++) 
        {
            for (int k = 0; k < a.m; k++) 
            {
                i64 r = a[i][k];
                if (r == 0) continue;
                for (int j = 0; j < b.m; j++) 
                {
                    res[i][j] = (res[i][j] + (i128)r * b[k][j]) % mod;
                }
            }
        }
        return res;
    }

    Matrix fast_pow(i64 b) const
    {
        Matrix res = Matrix::identity(n);
        Matrix base = *this;
        while (b) 
        {
            if (b & 1) res = res * base;
            base = base * base;
            b >>= 1;
        }
        return res;
    }

    i64 det() const 
    {
        assert(n == m);
        Matrix temp = *this;
        i64 res = 1;
        int w = 1;

        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                while (temp[j][i] != 0) 
                {
                    i64 t = temp[i][i] / temp[j][i];
                    for (int k = i; k < n; k++) 
                    {
                        temp[i][k] = (temp[i][k] - (i128)t * temp[j][k] % mod + mod) % mod;
                    }
                    for (int k = i; k < n; k++) 
                    {
                        swap(temp[i][k], temp[j][k]);
                    }
                    w = -w;
                }
            }
            if (temp[i][i] == 0) return 0;
            res = ((i128)res * temp[i][i]) % mod;
        }
        if (w == -1) res = (mod - res) % mod;
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