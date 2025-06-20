#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 0;
    for (int k = 1; k < n; k++)
    {
        auto l = m - (lower_bound(a.begin(), a.end(), k) - a.begin());
        auto r = a.end() - lower_bound(a.begin(), a.end(), n - k);

        ans += l * r - min(l, r);
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