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

    i64* operator[](int i) { return mt.data() + 1LL * i * m; }
    const i64* operator[](int i) const { return mt.data() + 1LL * i * m; }

    void identity()
    {
        for (int i = 0; i < n; i++) 
        {
            (*this)[i][i] = 0;
        }
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
                    res[i][j] = max(res[i][j], l[i][k] + r[k][j]);
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
    Matrix res(base.n, base.n, -INF);
    res.identity();
    while (b) 
    {
        if (b & 1) res = res * base;
        base = base * base;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n, m, k, R;
    cin >> n >> m >> k >> R;
    vector<i64> a(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> c[i];
    Matrix mt(1 << n, 1 << n, -INF);

    for (int s = 0; s < (1 << n); s++)
    {
        for (int t = 0; t < (1 << n); t++)
        {
            int tota = 0, totc = 0;
            for (int bit = 0; bit < n; bit++)
            {
                if (t >> bit & 1)
                {
                    totc += c[bit] + k * (s >> bit & 1);
                    tota += a[bit];
                }
            }

            if (totc <= m) mt[s][t] = tota;
        }
    }

    auto res = fast_pow(mt, R);

    i64 ans = -INF;
    for (int j = 0; j < (1 << n); j++) ans = max(ans, res[0][j]);

    cout << ans << "\n";
}

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}