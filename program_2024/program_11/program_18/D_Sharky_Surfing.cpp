#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, l;
    cin >> n >> m >> l;
    vector<pair<int, int>> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    for (int i = 0; i < m; i++)
        cin >> b[i].first >> b[i].second;
    priority_queue<int> q;
    int j = 0, k = 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < m && b[j].first < a[i].first)
            q.push(b[j++].second);
        int dist = a[i].second - a[i].first + 2;
        while (k < dist && !q.empty())
        {
            k += q.top();
            q.pop();
            ans++;
        }
        if (k < dist && q.empty())
        {
            cout << -1 << "\n";
            return;
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