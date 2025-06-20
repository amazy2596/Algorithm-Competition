#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a.rbegin(), a.rend());

    int ans = 0, cur = 1e9, l = 0;
    for (int i = 0; i < n; i++)
    {
        cur = min(cur, a[i]);
        if ((i - l + 1) * cur >= x)
            ans++, l = i + 1, cur = 1e9;
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