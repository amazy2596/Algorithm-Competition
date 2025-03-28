#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // sum - a[i] - a[r] <= y;
        // sum - a[i] - y <= a[r];
        auto l = lower_bound(a.begin() + i + 1, a.end(), sum - a[i] - y) - a.begin();
        
        // sum - a[i] - a[l] >= x;
        // sum - a[i] - x >= a[l];
        auto r = upper_bound(a.begin() + i + 1, a.end(), sum - a[i] - x) - a.begin() - 1;
        if (r >= l)
            ans += r - l + 1;
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