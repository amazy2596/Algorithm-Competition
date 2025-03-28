#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> mp;
    map<int, int> vis;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i != 0)
            mp[a[i] + i].push_back(i);
    }
    queue<int> q;
    q.push(n);
    vis[n] = 1;
    int ans = n;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        if (vis.find(i) != vis.end() && mp.find(i) != mp.end())
        {
            for (int j = 0; j < mp[i].size(); j++)
            {
                vis[i + mp[i][j]] = 1;
                ans = max(ans, i + mp[i][j]);
                q.push(i + mp[i][j]);
            }
            vis.erase(i);
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