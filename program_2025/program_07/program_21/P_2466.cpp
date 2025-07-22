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
    int x, y, v;
};

void solve()
{
    int n, x0;
    cin >> n >> x0;
    int sum = 0;
    vector<node> a(n + 2);
    a[n + 1] = {x0, 0, 0};
    for (int i = 1; i <= n; i++)
        cin >> a[i].x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].y;
        sum += a[i].y;
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i].v;
    sort(a.begin() + 1, a.end(), [&](node &a, node &b){
        return a.x < b.x;
    });

    vector<int> pre(n + 2);
    for (int i = 1; i <= n + 1; i++)
        pre[i] = pre[i - 1] + a[i].v;

    int total = pre[n + 1];
    vector<vector<array<int, 2>>> dp(n + 2, vector<array<int, 2>>(n + 2, {inf, inf}));
    
    for (int i = 1; i <= n + 1; i++)
    {
        if (a[i].x == x0)
        {
            dp[i][i][0] = dp[i][i][1] = 0;
        }
    }

    for (int len = 2; len <= n + 1; len++)
    {
        for (int l = 1; l + len - 1 <= n + 1; l++)
        {
            int r = l + len - 1;
            int cost1 = (a[l + 1].x - a[l].x) * (total - (pre[r] - pre[l]));
            int cost2 = (a[r].x - a[l].x) * (total - (pre[r] - pre[l]));
            dp[l][r][0] = min({dp[l][r][0], dp[l + 1][r][0] + cost1, dp[l + 1][r][1] + cost2});

            int cost3 = (a[r].x - a[r - 1].x) * (total - (pre[r - 1] - pre[l - 1]));
            int cost4 = (a[r].x - a[l].x) * (total - (pre[r - 1] - pre[l - 1]));
            dp[l][r][1] = min({dp[l][r][1], dp[l][r - 1][1] + cost3, dp[l][r - 1][0] + cost4});
        }
    }

    int mn = min(dp[1][n + 1][0], dp[1][n + 1][1]);
    double ans = (sum - mn) * 1.0l / 1000;

    cout << fixed << setprecision(3) << ans << "\n";
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