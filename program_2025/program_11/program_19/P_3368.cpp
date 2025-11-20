// Problem: 【模板】树状数组 2
// URL: https://www.luogu.com.cn/problem/P3368
// Author: amazy
// Date: 2025-11-19 15:47:32

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

struct Fenwick
{
    int n;
    vector<int> a, b;

    Fenwick() {}
    Fenwick(int _n) : n(_n), a(_n + 1), b(_n + 1) {}

    int lowbit(int x)
    {
        return x & -x;
    }

    void modify(int x, int k, vector<int> &v)
    {
        while (x >= 1 && x <= n)
        {
            v[x] += k;
            x += lowbit(x);
        }
    }

    // (r + 1) * (a[1] + ... + a[r]) - (b[1] * 1 + ... + b[r] * r)
    void update(int l, int r, int k)
    {
        modify(l, k, a);
        modify(r + 1, -k, a);

        modify(l, k * l, b);
        modify(r + 1, -k * (r + 1), b);
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

    int query(int l, int r)
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
    int n, m;
    cin >> n >> m;
    Fenwick fw(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        fw.update(i, i, x);
    }

    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            fw.update(x, y, k);
        }
        else 
        {
            int x;
            cin >> x;
            cout << fw.query(x, x) << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}