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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], ans += a[i];
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        ans += b[i];
        mp[b[i]]++;
    }

    sort(a.begin() + 1, a.end(), greater<int>());
    for (int i = 1; i <= n; i++)
    {
        auto it = mp.lower_bound(m - a[i]);
        if (it != mp.end())
        {
            ans -= m;
            (*it).second--;
            if ((*it).second == 0)
                mp.erase(it);
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