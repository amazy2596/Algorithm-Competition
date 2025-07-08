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
    vector<int> a(n + 1);
    int ans = 0, mn = inf;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
        ans += mn;
    }

    int cur = a[1] + min(a[1], a[2]);
    mn = min(a[1], a[2]);
    for (int j = 3; j <= n; j++)
    {
        ans = min(ans, cur);
        mn = min(mn, a[j]);
        cur += mn;
    }

    ans = min(ans, a[1] + a[2]);

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