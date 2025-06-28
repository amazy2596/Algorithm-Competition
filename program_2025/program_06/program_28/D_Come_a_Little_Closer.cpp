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
    vector<pair<int, int>> p(n);
    vector<int> a, b;
    int mn_x = inf, mx_x = -inf, mn_y = inf, mx_y = -inf;
    for (auto &[x, y] : p)
    {
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
        mn_x = min(mn_x, x);
        mx_x = max(mx_x, x);

        mn_y = min(mn_y, y);
        mx_y = max(mx_y, y);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (n == 1)
    {
        cout << "1\n";
        return;
    }

    int ans = inf * 5;
    for (auto [x, y] : p)
    {
        int cmnx = mn_x, cmxx = mx_x;
        int cmny = mn_y, cmxy = mx_y;
        if (x == cmnx)
            cmnx = a[1];
        if (x == cmxx)
            cmxx = a[n - 2];

        if (y == cmny)
            cmny = b[1];
        if (y == cmxy)
            cmxy = b[n - 2];

        int s = abs(cmxx - cmnx + 1) * abs(cmxy - cmny + 1);
        if (s == n - 1)
            s += min(abs(cmxx - cmnx + 1), abs(cmxy - cmny + 1));

        ans = min(ans, s);
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