#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-9;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

struct Fenwick
{
    int n;
    vector<int> a, b;

    Fenwick(int _n) : n(_n), a(_n + 1), b(_n + 1) {}

    int lowbit(int x)
    {
        return x & -x;
    }

    void add(int x, int k, vector<int> &v)
    {
        while (x <= n)
        {
            v[x] += k;
            x += lowbit(x);
        }
    }

    // (r + 1) * (a[1] + ... + a[r]) - (b[1] * 1 + ... + b[r] * r)
    void range_add(int l, int r, int k)
    {
        add(l, k, a);
        add(r + 1, -k, a);

        add(l, k * l, b);
        add(r + 1, -k * (r + 1), b);
    }

    int get(int x, vector<int> &v)
    {
        int res = 0;
        while (x > 0)
        {
            res += v[x];
            x -= lowbit(x);
        }

        return res;
    }

    int range_query(int l, int r)
    {
        if (l > r)
            return 0ll;

        int R = (r + 1) * get(r, a) - get(r, b);
        int L = l * get(l - 1, a) - get(l - 1, b);

        return R - L;
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