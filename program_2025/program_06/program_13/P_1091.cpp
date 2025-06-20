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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> L(n), R(n);
    vector<int> d;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(d.begin(), d.end(), a[i]);
        if (it == d.end())
            d.push_back(a[i]);
        else 
            *it = a[i];

        L[i] = d.size();
    }

    d.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        R[i] = d.size();
        auto it = lower_bound(d.begin(), d.end(), a[i]);
        if (it == d.end())
            d.push_back(a[i]);
        else 
            *it = a[i];
    }

    int ans = inf;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, n - L[i] - R[i]);
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}