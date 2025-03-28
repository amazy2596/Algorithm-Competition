#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), all;
    for (int i = 0; i < n; i++)
        cin >> a[i], all.push_back(a[i]);
    for (int i = 0; i < n; i++)
        cin >> b[i], all.push_back(b[i]);
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 0; i < all.size(); i++)
    {
        auto cnt = b.end() - lower_bound(b.begin(), b.end(), all[i]);
        auto num = a.end() - lower_bound(a.begin(), a.end(), all[i]);
        if ((cnt - num) <= k)
            ans = max(ans, all[i] * cnt);
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