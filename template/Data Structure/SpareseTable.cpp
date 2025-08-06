#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 inf = 1e18; 

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };

template<typename T>
struct ST 
{
    using Func = function<T(T, T)>;
    vector<vector<T>> a;
    Func op;
    int n;

    template<typename Func>
    ST(vector<T>& input, Func _op = [](T a, T b) { return max(a, b); }) : op(_op) 
    {
        n = input.size() - 1;

        int max_log = __lg(n);
        a.assign(n + 1, vector<T>(max_log + 1, 0));

        for (int i = 1; i <= n; i++) 
            a[i][0] = input[i];

        for (int j = 1; j <= max_log; j++) 
        {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) 
            {
                // [i + 2 ^ (j - 1) - 1, i + 2 ^ j - 1], [i + 2 ^ (j - 1), i + 2 ^ j - 1];
                a[i][j] = op(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) 
    {
        int j = __lg(r - l + 1);
        // [l, l + 2 ^ j - 1], [r - 2 ^ j + 1, r];
        return op(a[l][j], a[r - (1 << j) + 1][j]);
    }
};

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