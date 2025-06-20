#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        mp[b].push_back(a[i]);
    }
    int ans = 0;
    for (auto [b, v] : mp)
    {
        if (v.size() == 1)
        {
            cout << -1 << "\n";
            return;
        }
        ans += (v.size() + 1) / 2;
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