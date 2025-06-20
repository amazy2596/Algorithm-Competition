#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    int l = 0, r = 1;
    int ans = 1e12, cur = 0;
    while (r < n)
    {
        cur += abs(a[r] * a[r] - a[r - 1] * a[r - 1]);
        if (r - l + 1 == m)
        {
            ans = min(ans, cur);
            cur -= abs(a[l] * a[l] - a[l + 1] * a[l + 1]);
            l++;
        }

        r++;
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