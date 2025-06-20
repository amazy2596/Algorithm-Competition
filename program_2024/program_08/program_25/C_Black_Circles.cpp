#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    int target = (sx - ex) * (sx - ex) + (sy - ey) * (sy - ey);
    for (int i = 0; i < n; i++)
    {
        int temp = (a[i].first - ex) * (a[i].first - ex) + (a[i].second - ey) * (a[i].second - ey);
        if (temp <= target)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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