#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

int vis[1005][1005][11][2];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector s(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        for (int j = 0; j < t.length(); j++)
            s[i][j] = (t[j] == 'A' ? 0 : 1);
    }

    queue<array<int, 5>> q;
    // map<array<int, 4>, int> vis;
    q.push({{0, 0, 0, 1, 0}});
    while (!q.empty())
    {
        auto [x, y, dist, cnt, tar] = q.front();
        q.pop();

        // info
        // cout << x << " " << y << " " << dist << " " << cnt << " " << tar << "\n";

        if (x == n - 1 && y == m - 1)
        {
            cout << dist << "\n";
            return;
        }

        for (auto [dx, dy] : vector<array<int, 2>> {{0, 1}, {0, -1}, {1, 0}, {-1, 0}})
        {
            int nx = x + dx, ny = y + dy, ncnt, ntar;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (cnt == k)
            {
                ntar = tar ^ 1;
                ncnt = 1;
            }
            else 
            {
                ntar = tar;
                ncnt = cnt + 1;
            }

            if (s[nx][ny] != ntar)
                continue;

            if (vis[nx][ny][ncnt][ntar])
                continue;
            vis[nx][ny][ncnt][ntar]++;

            q.push({{nx, ny, dist + 1, ncnt, ntar}});
        }
    }

    cout << -1 << "\n";
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