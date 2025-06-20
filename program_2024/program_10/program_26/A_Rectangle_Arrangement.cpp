#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    int ans = 0;
    int mx_i = 0, mx_j = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > mx_i)
        {
            ans += 2 * (a[i].first - mx_i);
            mx_i = a[i].first;
        }
        if (a[i].second > mx_j)
        {
            ans += 2 * (a[i].second - mx_j);
            mx_j = a[i].second;
        }
    }
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