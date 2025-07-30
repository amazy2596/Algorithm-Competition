#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

template<typename T>
struct ST 
{
    using _func = function<T(T, T)>;
    vector<vector<T>> a;
    _func op;
    int n;

    ST(vector<T>& input, _func _op = [](T a, T b) { return max(a, b); }) : op(_op) 
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