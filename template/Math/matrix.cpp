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

// snippet-begin:
struct Matrix 
{
    int n;
    vector<vector<i64>> a;

    Matrix(int _n): n(_n) { a.resize(n, vector<i64>(n, 0)); }

    Matrix operator*(const Matrix &o) const 
    {
        Matrix res(n);
        for (int i = 0; i < n; i++) 
        {
            for (int k = 0; k < n; k++) 
            {
                if (!a[i][k]) continue;
                for (int j = 0; j < n; j++) 
                {
                    res.a[i][j] = (res.a[i][j] + a[i][k] * o.a[k][j]) % mod;
                }
            }
        }
        return res;
    }

    Matrix fast_pow(Matrix a, i64 b) 
    {
        Matrix res(a.n);
        while (b) 
        {
            if (b & 1) res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }
};
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