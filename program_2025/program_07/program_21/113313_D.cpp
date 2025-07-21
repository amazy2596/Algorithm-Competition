#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, m;
    cin >> n >> m;
    if ((m & 1) == 0)
    {
        cout << "-1\n";
        return;
    }

    // if (n == 1 && m >= 2)
    // {
    //     cout << "-1\n";
    //     return;
    // }

    vector<int> vis(n + 1), p(1);
    for (int k = 32; k >= 1; k--)
    {
        if ((m >> k) & 1 == 1)
        {
            if ((1ll << k) <= n)
            {
                vis[(1ll << k)] = 1;
                p.push_back((1ll << k));
            }
            else 
            {
                cout << "-1\n";
                return;
            }
        }
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i < p.size(); i++)
        ans.push_back({i, i});

    if (p.size() <= n)
        ans.push_back({p.size(), n});

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            p.push_back(i);
    }

    for (int i = 1; i <= n; i++)
        cout << p[i] << " ";
    cout << "\n";
    cout << ans.size() << "\n";
    for (auto [x, y] : ans)
        cout << x << " " << y << "\n";
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