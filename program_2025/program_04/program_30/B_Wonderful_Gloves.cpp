#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> l(n), r(n), b(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> l[i];
    for (int i = 0; i < n; i++)
        cin >> r[i];

    for (int i = 0; i < n; i++)
    {
        ans += max(l[i], r[i]);
        b[i] = min(l[i], r[i]);
    }

    sort(b.rbegin(), b.rend());
    for (int i = 0; i < k - 1; i++)
        ans += b[i];
    
    cout << ans + 1 << "\n";
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