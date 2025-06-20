#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];
    
    int tar = ((1 + n) * n) / 2;
    if (sum != tar)
    {
        cout << -1 << "\n";
        return;
    }

    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs((i + 1) - a[i]);

    cout << ans / 2 << "\n";
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