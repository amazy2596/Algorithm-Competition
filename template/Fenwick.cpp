#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

struct Fenwick
{
    int n;
    vector<int> a;

    Fenwick(int size)
    {
        n = size;
        a.resize(n, 0);
    }

    int lowbit(int x)
    {
        return x & -x;
    }

    void update(int x, int k)
    {
        while (x > 0 && x <= n)
        {
            a[x] += k;
            x += lowbit(x);
        }
    }

    int query(int r)
    {
        int res = 0;
        while (r > 0)
        {
            res += a[r];
            r -= lowbit(r);
        }
        return res;
    }

    int query(int l, int r)
    {
        if (l > r)
            return 0;
        return query(r) - query(l - 1);
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
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}