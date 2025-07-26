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
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    int ans = 0;
    vector<int> vis(10005);
    for (int tar = 1e4; tar >= 2; tar--)
    {
        int tmp = 0;
        vis.assign(10005, 0);
        for (auto [key, val] : mp)
        {
            if (key >= tar || vis[key] || vis[tar - key])
                continue;
            vis[key] = 1;
            vis[tar - key] = 1;

            if (key * 2 == tar)
                tmp += val / 2;
            else 
                tmp += min(val, mp[tar - key]);
        }

        ans = max(ans, tmp * 2);
    }

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}