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
    vector<int> a(2 * n + 1), pre(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        if (i <= n)
            cin >> a[i];
        else 
            a[i] = a[i - n];
        pre[i] = pre[i - 1] + a[i];
    }

    int m = 2 * n;
    vector<vector<int>> dpMIN(m + 1, vector<int>(m + 1, inf)), dpMAX(m + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; i++)
        dpMIN[i][i] = 0;
    for (int len = 2; len <= m; len++)
    {
        for (int l = 1; l + len - 1 <= m; l++)
        {
            int r = l + len - 1;
            for (int p = l; p < r; p++)
            {
                dpMIN[l][r] = min({dpMIN[l][r], dpMIN[l][p] + dpMIN[p + 1][r] + pre[r] - pre[l - 1]});
                dpMAX[l][r] = max({dpMAX[l][r], dpMAX[l][p] + dpMAX[p + 1][r] + pre[r] - pre[l - 1]});
            }
        }
    }

    int mn = inf, mx = 0;
    for (int l = 1; l + n - 1 <= 2 * n; l++)
    {
        int r = l + n - 1;
        mn = min(mn, dpMIN[l][r]);
        mx = max(mx, dpMAX[l][r]);
    }

    cout << mn << "\n" << mx << "\n";
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