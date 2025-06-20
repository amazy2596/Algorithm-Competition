#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(x);
    for (int i = 0; i < x; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int ans = x - 2;
    for (int i = 1; i < x; i++)
        if (a[i] - a[i - 1] == 2)
            ans++;
    ans += abs(a[x - 1] - a[0]) == n - 2;
    cout << ans << "\n";
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