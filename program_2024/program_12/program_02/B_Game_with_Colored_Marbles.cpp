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
    int one = 0, ans = 0;
    for (auto [k, v] : mp)
        one += v == 1;
    if (one % 2 == 1)
        ans += (one + 1) / 2 * 2;
    else
        ans += one;
    cout << ans + (mp.size() - one) << "\n";
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