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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> pre(n + 1), suf(n + 2);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + ((sum + k - 1) / k);
        sum += a[i];
    }

    sum = 0;
    for (int i = n; i >= 1; i--)
    {
        suf[i] = suf[i + 1] + ((sum + k - 1) / k);
        sum += a[i];
    }

    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, pre[i] + suf[i]);
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