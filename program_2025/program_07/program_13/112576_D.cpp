#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i];

    vector<vector<int>> pos(n + 1);
    for (int i = 1; i <= 2 * n; i++)
        pos[a[i]].push_back(i);

    int ans = 0;
    int mn = inf, mx = -inf;
    for (int i = 1; i <= n; i++)
    {
        if (pos[i][0] <= n)
            mn = min(mn, pos[i][1]);
        if (pos[i][1] >= n + 1)
            mx = max(mx, pos[i][0]);
        ans += pos[i][1] - pos[i][0] - 1;
    }

    ans += 2 * max(0ll, mx - mn);
    cout << ans << "\n";
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