#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = j;

    vector<array<int, 3>> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.push_back({i, 1, i});
        reverse(g[i].begin() + 1, g[i].begin() + i + 1);

        if (i != n)
        {
            ans.push_back({i, i + 1, n});
            reverse(g[i].begin() + i + 1, g[i].end());
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << ans.size() << "\n";
    for (auto [i, l, r] : ans)
        cout << i << " " << l << " " << r << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}