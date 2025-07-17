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

    auto check = [&](int l, int r)
    {
        if (a[l] <= a[l + 1] && a[l + 1] <= a[l + 2])
            return 0;
        if (a[l] <= a[l + 1] && a[l + 1] <= a[l + 3])
            return 0;
        if (a[l] <= a[l + 2] && a[l + 2] <= a[l + 3])
            return 0;
        if (a[l + 1] <= a[l + 2] && a[l + 2] <= a[l + 3])
            return 0;

        if (a[l] >= a[l + 1] && a[l + 1] >= a[l + 2])
            return 0;
        if (a[l] >= a[l + 1] && a[l + 1] >= a[l + 3])
            return 0;
        if (a[l] >= a[l + 2] && a[l + 2] >= a[l + 3])
            return 0;
        if (a[l + 1] >= a[l + 2] && a[l + 2] >= a[l + 3])
            return 0;

        return 1;
    };

    int ans = n + n - 1;
    for (int i = 3; i <= n; i++)
    {
        if (!((a[i - 2] <= a[i - 1] && a[i - 1] <= a[i]) || (a[i - 2] >= a[i - 1] && a[i - 1] >= a[i])))
            ans++;
    }

    for (int i = 4; i <= n; i++)
    {
        if (check(i - 3, i))
            ans++;
    }

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