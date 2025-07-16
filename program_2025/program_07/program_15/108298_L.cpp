#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

// 单点修改 + 区间查询 + 第k小值
struct Fenwick
{
    int n;
    vector<int> a;

    Fenwick(int _n) : n(_n), a(_n + 1) {}

    int lowbit(int x)
    {
        return x & -x;
    }

    void update(int x, int k)
    {
        while (x >= 1 && x <= n)
        {
            a[x] += k;
            x += lowbit(x);
        }
    }

    int pre(int r)
    {
        int res = 0;   
        while (r >= 1)
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
        return pre(r) - pre(l - 1);
    }

    int kth(int k)
    {
        int ans = 0;
        for (int p = log2l(n); p >= 0; p--)
        {
            int step = 1ll << p;
            if (ans + step <= n && a[ans + step] < k)
            {
                k -= a[ans + step];
                ans += step;
            }
        }

        return ans + 1;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> all(1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i], all.push_back(a[i]);

    auto tmp = a;
    vector<int> p(q + 1), v(q + 1);
    for (int i = 1; i <= q; i++)
    {
        cin >> p[i] >> v[i];
        tmp[p[i]] += v[i];
        all.push_back(tmp[p[i]]);
    }

    sort(all.begin() + 1, all.end());
    all.erase(unique(all.begin() + 1, all.end()), all.end());
    unordered_map<int, int> id;
    for (int i = 1; i < all.size(); i++)
        id[all[i]] = i;

    Fenwick fw(all.size() + 5);
    for (int i = 1; i <= n; i++)
        fw.update(id[a[i]], 1);

    int tar = n / 2;
    for (int i = 1; i <= q; i++)
    {
        fw.update(id[a[p[i]]], -1);
        a[p[i]] += v[i];
        fw.update(id[a[p[i]]], 1);

        int l = 0, r = all.size() - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            int res = fw.query(mid + 1, all.size() - 1);
            if (res >= tar)
                l = mid;
            else 
                r = mid - 1;
        }

        if (l < 1)
            cout << "0\n";
        else 
            cout << fw.query(1, l) << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}