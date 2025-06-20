#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n / 2; i++)
    {
        if (a[i - 1] == a[i] || a[n - i + 1] == a[n - i + 2])
            swap(a[i], a[n - i + 1]);
    }
    int ans = 0;
    for (int i = 2; i <= n; i++)
        ans += a[i - 1] == a[i];
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