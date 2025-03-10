#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

class Fenwick
{
    public:
        int n;
        vector<int> tree;

        Fenwick(int size)
        {
            n = size;
            tree.resize(n + 1);
        }

        int lowbit(int x)
        {
            return x & -x;
        }

        void update(int x, int k)
        {
            while (x > 0 && x <= n)
            {
                tree[x] += k;
                x += lowbit(x);
            }
        }

        int query(int r)
        {
            int res = 0;
            while (r)
            {
                res += tree[r];
                r -= lowbit(r);
            }

            return res;
        }

        int query(int l, int r)
        {
            return query(r) - query(l - 1);
        }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + m + 1);
    vector<pair<int, int>> p;
    for (int i = 1; i <= n + m; i++)
    {
        cin >> a[i];
        if (i == n)
            reverse(a.begin() + 1, a.begin() + n + 1);
    }

    for (int i = 1; i <= n + m; i++)
        p.emplace_back(a[i], i);

    Fenwick f(n + m + 1);
    for (int i = 1; i <= n + m + 1; i++)
        f.update(i, 1);

    sort(p.begin(), p.end(), greater<pair<int, int>>());
    int last = n;
    int ans = 0;

    for (int i = 0; i < p.size(); i++)
    {
        int nxt = p[i].second;
        f.update(nxt, -1);
        if (nxt > last)
            ans += f.query(last + 1, nxt);
        else if (nxt < last)
            ans += f.query(nxt, last);
        
        last = nxt;
    }

    cout << ans << "\n";
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