#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

// snippet-begin:
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
                mt[i++] = x;
            }
        }
    }

    i64* operator[](int i) { return mt.data() + i * m; }
    const i64* operator[](int i) const { return mt.data() + i * m; }

    void identity()
    {
        assert(n == m);
        fill(mt.begin(), mt.end(), 0);
        for (int i = 0; i < n; i++) (*this)[i][i] = 1;
    }

    friend Matrix operator*(const Matrix &l, const Matrix &r) 
    {
        assert(l.m == r.n);
        Matrix res(l.n, r.m);
        for (int i = 0; i < l.n; i++) 
        {
            for (int k = 0; k < l.m; k++) 
            {
                for (int j = 0; j < r.m; j++) 
                {
                    res[i][j] += l[i][k] * r[k][j];
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
    Matrix res(base.n, base.n);
    res.identity();
    while (b) 
    {
        if (b & 1) res = res * base;
        base = base * base;
        b >>= 1;
    }
    return res;
}
// snippet-end:

void solve()
{
    
}

int main()
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