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
    int n;
    cin >> n;
    vector<vector<int>> g(n + 2, vector<int>(n + 2, -1));
    int x = (n + 1) / 2, y = (n + 1) / 2;
    int cnt = 0, cur = 0;
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool f = 0;
    while (cnt < n * n)
    {
        g[x][y] = cnt++;
        int ncur = (cur + 1) % 4;
        auto [dx, dy] = dir[ncur];
        if (f && g[x + dx][y + dy] == -1)
        {
            x += dx, y += dy;
            cur = ncur;
        }
        else 
        {
            dx = dir[cur].first, dy = dir[cur].second;
            x += dx, y += dy;
        }
        f = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << g[i][j] << " ";
        }

        cout << "\n";
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}