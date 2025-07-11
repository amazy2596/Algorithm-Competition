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
        while (x <= n)
        {
            a[x] += k;
            x += lowbit(x);
        }
    }

    int pre(int r)
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int k = 0;
    Fenwick fw(n);
    for (int i = 1; i <= n; i++)
    {
        fw.update(a[i], 1);
        k += fw.query(a[i] + 1, n);
    }

    if (k == 0 || k == n * (n - 1) / 2)
    {
        cout << "-1\n";
        return;
    }

    vector<int> L0(n + 1), suf(n + 2);
    int rem = k;

    for (int i = n; i >= 1; i--)
        suf[i] = suf[i + 1] + n - i;

    for (int i = 1; i <= n; i++)
    {
        int mx = suf[i + 1];
        L0[i] = max(0ll, rem - mx);
        rem -= L0[i];
    }

    auto unrank = [&](vector<int> &L)
    {
        vector<int> b(n + 1);
        Fenwick fw(n);
        for (int i = 1; i <= n; i++)
            fw.update(i, 1);

        for (int i = 1; i <= n; i++)
        {
            int now = fw.kth(L[i] + 1);
            fw.update(now, -1);
            b[i] = now;
        }

        return b;
    };

    auto b = unrank(L0);

    if (a != b)
    {
        for (int i = 1; i <= n; i++)
            cout << b[i] << " ";
        cout << "\n";
        return;
    }

    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + L0[i];

    int pos = -1;
    for (int i = n; i >= 1; i--)
    {
        if (L0[i] < n - i)
        {
            int pref = pre[i - 1];
            int tmp = k - pref - (L0[i] + 1);
            if (tmp >= 0 && tmp <= suf[i + 1])
            {
                pos = i;
                break;
            }
        }
    }

    if (pos == -1)
    {
        cout << "-1\n";
        return;
    }

    rem = k;
    vector<int> L1(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int mx = suf[i + 1];
        if (i < pos)
            L1[i] = L0[i];
        else if (i == pos)
            L1[i] = L0[i] + 1;
        else 
            L1[i] = max(0ll, rem - mx);

        rem -= L1[i];
    }

    auto c = unrank(L1);
    if (a != c)
    {
        for (int i = 1; i <= n; i++)
            cout << c[i] << " ";
        cout << "\n";
        return;
    }

    cout << "-1\n";
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