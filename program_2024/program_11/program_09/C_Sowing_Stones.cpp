#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> p[i].first;
    for (int i = 1; i <= m; i++)
        cin >> p[i].second;
    sort(p.begin(), p.end());
    int ans = 0, pos = 1;
    for (int i = 1; i <= m; i++)
    {
        if (pos < p[i].first)
        {
            cout << -1 << "\n";
            return;
        }
        ans += ((pos - p[i].first + pos - p[i].first + p[i].second - 1) * p[i].second) / 2;
        pos += p[i].second;
    }
    cout << (pos == n + 1 ? ans : -1) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}