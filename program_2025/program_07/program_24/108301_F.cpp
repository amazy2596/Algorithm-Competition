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
    int n, k, c;
    cin >> n >> k >> c;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (c == 0)
    {
        sort(a.rbegin(), a.rend());
        int ans = 0;
        for (int i = 1; i <= k; i++)
            ans += a[i];
        cout << ans << "\n";
    }

    vector<int> b(n + 1);
    for (int i = 1; i <= k; i++)
        b[i] = a[i] - c * i + (k - i) * c;

    for (int j = k + 1; j <= n; j++)
    {
        int cost = a[j] - j * c;

        
    }
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