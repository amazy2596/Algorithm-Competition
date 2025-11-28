#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n, k;
    cin >> n >> k;
    int s, t;
    cin >> s >> t;

    vector<vector<int>> vis(n + 1, vector<int>(n + 1));
    queue<tuple<int, int, int>> q;
    q.push({s, t, 0});

    while (!q.empty())
    {
        auto [x, y, step] = q.front();
        q.pop();

        if (vis[x][y]) continue;
        vis[x][y] = 1;
        if (step == k) continue;

        for (auto [dx, dy] : vector<pair<int, int>> {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}})
        {
            int nx = x + dx, ny = y + dy;
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            q.push({nx, ny, step + 1});
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++)
        {
            // cout << vis[i][j] << " ";
            ans += vis[i][j];
        }
        // cout << "\n";
    }

    cout << ans << "\n";
}

int main()
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