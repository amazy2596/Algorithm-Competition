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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    vector<int> row(n + 1, -inf), col(m + 1, -inf);
    int mx = -inf;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            row[i] = max(row[i], g[i][j]);
            col[j] = max(col[j], g[i][j]);

            mx = max(mx, g[i][j]);
        }
    }

    vector<int> rcnt(n + 1), ccnt(m + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == mx)
            {
                rcnt[i]++;
                ccnt[j]++;
                cnt++;
            }
        }
    }

    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int r = row[i], c = col[j];
            int rc = rcnt[i], cc = ccnt[j];
            int sum = rc + cc - (g[i][j] == mx);
            int cmx = mx;
            r--, c--;
            if (sum == cnt)
                cmx--;
            ans = min(ans, max({cmx, r, c}));
        }
    }

    cout << ans << "\n";
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