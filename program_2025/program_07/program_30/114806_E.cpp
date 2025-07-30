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
    int n, b;
    cin >> n >> b;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<pair<int, int>> p(b + 1);
    for (int i = 1; i <= b; i++)
        cin >> p[i].first >> p[i].second;

    sort(p.begin() + 1, p.end());
    vector<int> pre(n + 1);
    for (int i = 1; i <= b; i++)
        pre[i] = pre[i - 1] + p[i].second;

    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(p.begin() + 1, p.end(), make_pair(a[i], inf));
        cout << pre[it - p.begin() - 1] << " ";
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