#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int ans1 = (n + 1) / 2, ans2 = n / 2;
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i += 2)
        mx1 = max(mx1, a[i]);
    for (int i = 1; i < n; i += 2)
        mx2 = max(mx2, a[i]);
    cout << max(ans1 + mx1, ans2 + mx2) << "\n";
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