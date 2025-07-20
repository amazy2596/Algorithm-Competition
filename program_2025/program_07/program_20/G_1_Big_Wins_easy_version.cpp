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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int m = 100, ans = 0;
    for (int k = 1; k <= m; k++)
    {
        vector<int> b(n + 1), pre(n + 1), mn(n + 1), mx(n + 2);
        for (int i = 1; i <= n; i++)
        {
            b[i] = (a[i] >= k ? 1 : -1);
            pre[i] = pre[i - 1] + b[i];
            mn[i] = min(mn[i - 1], pre[i]);
        }
        mx[n + 1] = -inf;
        for (int i = n; i >= 1; i--)
            mx[i] = max(mx[i + 1], pre[i]);

        for (int i = 1; i <= n; i++)
        {
            if (mn[i - 1] <= mn[i] || mx[i - 1] <= mx[i])
                ans = max(ans, k - a[i]);
        }
    }

    cout << ans << "\n";
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