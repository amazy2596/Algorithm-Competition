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
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> g[i], g[i] = " " + g[i];

    int sum = 0;
    vector<vector<int>> pre(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            pre[i][j] = pre[i - 1][j] + (g[i][j] == 'g'), sum += g[i][j] == 'g';

    int ans = -inf;
    k--;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == '.')
            {
                int u = max(1ll, i - k), d = min(n, i + k);
                int l = max(1ll, j - k), r = min(m, j + k);
                int sub = 0;
                for (int o = l; o <= r; o++)
                    sub += pre[d][o] - pre[u - 1][o];

                ans = max(ans, sum - sub);
            }
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