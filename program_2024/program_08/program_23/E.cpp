#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first;
    for (int i = 0; i < n; i++)
        cin >> a[i].second;
    sort(a.begin(), a.end(), [&](pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    });
    priority_queue<int> q;
    int p = 0;
    while (p < n)
    {
        int r = a[p].first + a[p].second;
        int size = 1;
        while (p + 1 < n && r >= a[p + 1].second)
        {
            p++, size++;
            r = max(r, a[p].first + a[p].second);
        }
        p++;
        q.push(size);
    }

    int ans = 0;
    while (m-- && !q.empty())
    {
        ans += q.top();
        q.pop();
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