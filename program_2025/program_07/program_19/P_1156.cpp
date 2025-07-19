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
    int t, h, f;
    bool operator<(node o)
    {
        auto x = tuple(t, h, f);
        auto y = tuple(o.t, o.h, o.f);
        return x < y;
    }
};

void solve()
{
    int d, g;
    cin >> d >> g;
    vector<node> a(g + 1);
    for (int i = 1; i <= g; i++)
        cin >> a[i].t >> a[i].f >> a[i].h;
    sort(a.begin() + 1, a.end());

    int maxD = 3005;
    vector<vector<int>> dp(g + 1, vector<int>(maxD + 1, -inf));
    dp[0][0] = 10;
    for (int i = 1; i <= g; i++)
    {
        for (int j = 0; j <= maxD; j++)
        {
            if (dp[i - 1][j] >= a[i].t)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i].f);

            if (j >= a[i].h && dp[i - 1][j - a[i].h] >= a[i].t)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].h]);
        }
    }

    int maxH = 0;
    int maxT = 10;
    for (int i = 1; i <= g; i++)
    {
        for(int j = 0; j <= maxD; j++)
        {
            if(dp[i][j] - a[i].t >= 0)
                maxH = max(maxH, j);
            maxT = max(maxT, dp[i][j]);
        }
        if(maxH >= d)
        {
            cout << a[i].t << "\n";
            return;
        }
    }
    cout << maxT << "\n";
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