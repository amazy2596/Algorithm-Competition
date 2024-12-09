#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k, a, b, x, y;
    cin >> n >> k >> a >> b >> x >> y;
    a--, b--;

    vector<int> need(n, 1e9);
    unordered_set<int> vis;
    queue<pair<int, int>> q;
    q.push({a, 0});
    while (!q.empty())
    {
        auto [pos, time] = q.front();
        q.pop();
        if (vis.find(pos) != vis.end())
            continue;
        need[pos] = min(need[pos], time);

        int ne = (pos + x) % n;
        q.push({ne, time + 1});
        vis.insert(ne);

        int prev = (pos - y + n) % n;
        q.push({prev, time + 1});
        vis.insert(prev);
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++)
        ans = min({ans, need[i], need[(i + n / 2) % n] + 1});
    cout << (ans == 1e9 ? -1 : ans) << "\n";
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