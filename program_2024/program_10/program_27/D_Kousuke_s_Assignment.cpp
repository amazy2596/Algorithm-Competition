#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = pre[i - 1] + a[i];
    int ans = 0;
    map<int, int> mp;
    for (int i = 0; i <= n; i++)
    {
        if (mp.find(pre[i]) != mp.end())
        {
            ans += mp[pre[i]];
            mp.clear();
        }
        mp[pre[i]]++;
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}