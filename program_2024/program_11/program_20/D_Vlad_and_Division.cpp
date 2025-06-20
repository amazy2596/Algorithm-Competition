#include <bits/stdc++.h>
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
    int ans = 0, cnt = 0;
    for (auto [key, val] : mp)
    {
        int y = 0;
        for (int k = 30; k >= 0; k--)
            y |= (((key >> k) & 1) ^ 1) << k;
        if (mp.find(y) != mp.end())
        {
            int val_y = mp[y];
            ans += max(val, val_y);
        }
        else
            cnt += val;
    }
    cout << ans / 2 + cnt << "\n";
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