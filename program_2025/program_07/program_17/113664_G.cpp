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

    int mn = *min_element(a.begin() + 1, a.end());
    vector<int> l(n + 1), r(n + 1);
    int cur = 0, mx = -inf;
    for (int i = 1; i <= n; i++)
    {
        cur = max(a[i], cur + a[i]);
        mx = max(mx, cur);
        l[i] = mx;
    }

    cur = 0, mx = -inf;
    for (int i = n; i >= 1; i--)
    {
        cur = max(a[i], cur + a[i]);
        mx = max(mx, cur);
        r[i] = mx;
    }

    int ans = -inf;
    for (int i = 1; i <= n - 1; i++)
        ans = max(ans, l[i] + r[i + 1]);

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}