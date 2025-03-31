#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (k == 1)
    {
        int mx = 0;
        for (int i = 1; i < n - 1; i++)
            mx = max(mx, a[i]);
        vector<int> temp = {mx, a[0], a[n - 1]};
        sort(temp.begin(), temp.end());
        cout << temp[1] + temp[2] << "\n";
        return;
    }

    sort(a.rbegin(), a.rend());
    int ans = accumulate(a.begin(), a.begin() + k + 1, 0ll);
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