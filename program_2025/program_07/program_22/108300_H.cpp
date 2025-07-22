#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct node
{
    int u, l, r;

    bool operator<(node o)
    {
        return l < o.l;
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> fa(n + 1);
    for (int i = 2; i <= n; i++)
        cin >> fa[i];

    vector<node> seg(k);
    for (auto &[u, l, r] : seg)
        cin >> u >> l >> r;
    sort(seg.begin(), seg.end());

    vector<int> vis(n + 1, inf);
    vis[1] = 1;
    for (auto [u, l, r] : seg)
    {
        if (vis[u] != inf)
        {
            cout << l << "\n";
            return;
        }
        
        int x = u;
        vector<int> tmp;
        while (true)
        {
            if (vis[x] != inf)
                break;
            tmp.push_back(x);
            x = fa[x];
        }
        reverse(tmp.begin(), tmp.end());

        int t = l;
        for (auto v : tmp)
        {
            vis[v] = t;
            t++;

            if (t == r + 1)
                break;
        }

        if (vis[u] != inf)
        {
            cout << vis[u] << "\n";
            return;
        }
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