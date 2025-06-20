#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    deque<int> d;
    for (int i = 0; i < n; i++)
    {
        if (i % 2)
            d.push_back(a[i]);
        else
            d.push_front(a[i]);
    }
    double ans = 0;
    for (int i = 1; i < n; i++)
        ans += (d[i - 1] + d[i]) * 1.0l / 2;
    cout << fixed << setprecision(2) << ans << "\n";
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