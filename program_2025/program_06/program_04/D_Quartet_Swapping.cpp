#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
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
    int n;
    cin >> n;
    vector<int> a, b;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (i % 2 == 1)
            a.push_back(x);
        else 
            b.push_back(x);
    }

    auto f = [&](vector<int> &v)
    {
        Fenwick fw(n + 1);
        int res = 0;
        for (auto x : v)
        {
            res += fw.query(x + 1, n);
            fw.update(x, 1);
        }

        return res;
    };

    int v = (f(a) % 2 != f(b) % 2);

    ranges::sort(a), ranges::sort(b);

    vector<int> ans(1);
    int i = 0, j = 0;
    for (int k = 1; k <= n; k++)
    {
        if (k % 2 == 1)
            ans.push_back(a[i++]);
        else 
            ans.push_back(b[j++]);
    }

    if (v)
        swap(ans[n], ans[n - 2]);

    for (int k = 1; k <= n; k++)
        cout << ans[k] << " ";
    cout << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init()
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}