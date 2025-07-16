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

// 区间修改 + 区间查询
struct Fenwick
{
    int n;
    vector<int> a, b;

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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;

    Fenwick fw(n + 1);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            fw.update(l, r, 1);
        }
        else if (op == 2)
        {
            int len, a, b;
            cin >> len >> a >> b;
            for (int i = 1; i <= n; i++)
            {
                int res = fw.query(i, i);
                s[i] = ((s[i] - '0') ^ res + '0');
                fw.update(i, i, -res);
            }
            string x = s.substr(a, len);
            string y = s.substr(b, len);

            int ans = 0;
            int l = 0;
            for (int j = 0; j < len; j++)
            {
                if (x[j] != y[j])
                {
                    int num = (j - 1) - l + 1;
                    ans += (num) * (num + 1) / 2;
                    l = j + 1;
                }
            }
            int num = (len - 1) - l + 1;
            ans += num * (num + 1) / 2;

            cout << ans << endl;
        }
    }
}

signed main()
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