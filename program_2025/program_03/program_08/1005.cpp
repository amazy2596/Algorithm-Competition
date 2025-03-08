#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

struct Node
{
    int x, y, dir, time;

    bool const operator<(Node other) const 
    {
        return time > other.time;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector t(n + 1, vector<int>(m + 1));
    vector d(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> d[i][j];

    vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
    vector<vector<vector<int>>> dist(n + 1, vector<vector<int>>(m + 1, vector<int>(4, 1e18l)));
    dist[1][1][0] = t[1][1];
    priority_queue<Node> q;
    q.push({1, 1, 0, dist[1][1][0]});
    while (!q.empty())
    {
        auto [x, y, dir, time] = q.top();
        q.pop();

        if (time != dist[x][y][dir])    
            continue;

        int nx = x + dx[dir], ny = y + dy[dir];
        if (!(nx < 1 || ny < 1 || nx > n || ny > m))
        {
            if (dist[nx][ny][dir] > dist[x][y][dir] + t[nx][ny])
            {
                dist[nx][ny][dir] = dist[x][y][dir] + t[nx][ny];
                q.push({nx, ny, dir, dist[nx][ny][dir]});
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (dist[x][y][i] > dist[x][y][dir] + d[x][y])
            {
                dist[x][y][i] = dist[x][y][dir] + d[x][y];
                q.push({x, y, i, dist[x][y][i]});
            }
        }
    }

    cout << dist[n][m][2] << "\n";
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