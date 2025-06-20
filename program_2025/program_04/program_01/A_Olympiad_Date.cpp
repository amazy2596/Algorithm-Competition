#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp, check = {{0, 3}, {1, 1}, {2, 2}, {3, 1}, {5, 1}};
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (ans != -1)
            continue;

        mp[a[i]]++;
        bool f = 1;
        for (auto [key, val] : check)
        {
            if (mp[key] < val)
            {
                f = 0;
                break;
            }
        }

        if (f)
            ans = i;
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