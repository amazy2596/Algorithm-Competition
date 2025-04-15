#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    vector<int> a;
    for (auto [key, val] : mp)
    {
        if (val >= 2)
            a.push_back(key);
    }

    int last = -1, len = -1;
    int ans = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (last >= 2)
        {
            mp[len] -= 2;
            mp[a[i]] -= 2;
            ans += a[i] * len;
        }

        if (mp[a[i]] >= 4)
        {
            int cnt = mp[a[i]] / 4;
            ans += cnt * a[i] * a[i];
            mp[a[i]] -= cnt * 4;
        }

        if (mp[a[i]] >= 2)
        {
            last = mp[a[i]];
            len = a[i];
        }
        else 
        {
            last = -1;
            len = -1;
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
    // cin >> T;
    while (T--)
        solve();
    return 0;
}