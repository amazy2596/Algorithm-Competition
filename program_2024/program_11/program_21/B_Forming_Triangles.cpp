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
    int ans = 0, sum = 0;
    for (auto [key, val] : mp)
    {
        if (val >= 3)
            ans += val * (val - 1) * (val - 2) / 6;
        if (val >= 2)
            ans += val * (val - 1) / 2 * sum;
        sum += val;
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