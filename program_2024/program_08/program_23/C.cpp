#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1005;
int n, m;
vector<string> g(N);
int vis[N][N], cnt[N][N];
bool f = 0;

struct node 
{
    int x, y;
};

void check(int x, int y)
{
    for (int dx = x; dx >= 0; dx--)
    {
        if (cnt[dx][y] == 1)
        {
            f = 1;
            return;
        }
    }

    for (int dx = x; dx < n; dx++)
    {
        if (cnt[dx][y] == 1)
        {
            f = 1;
            return;
        }
    }

    for (int dy = y; dy >= 0; dy--)
    {
        if (cnt[x][dy] == 1)
        {
            f = 1;
            return;
        }
    }

    for (int dy = y; dy < m; dy++)
    {
        if (cnt[x][dy] == 1)
        {
            f = 1;
            return;
        }
    }
}

void bfs(int i, int j)
{
    queue<node> q;
    q.push({i, j});

    while (!q.empty())
    {
        if (f)
            return;

        auto top = q.front();
        q.pop();
        int x = top.x, y = top.y;
        if (vis[x][y])
            continue;
        vis[x][y] = 1;

        bool isFirst = 1;

        for (auto [dx, dy] : vector<pair<int, int>>{{-1, 0}, {0, 1}, {1, 0}, {0, -1}})
        {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (g[i][j] == 'E')
                cnt[nx][ny] = 1;
            if (g[i][j] == 'E' && g[nx][ny] == 'S')
            {
                f = 1;
                return;
            }
            if (isFirst && g[nx][ny] == '#' && g[i][j] == 'S')
            {
                check(x, y);
                isFirst = 0;
            }
            if (g[nx][ny] == '#')
                continue;
            q.push({nx, ny});
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> g[i];
    int sx, sy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'E')
            {
                bfs(i, j);
                cnt[i][j] = 1;
            }
            if (g[i][j] == 'S')
                sx = i, sy = j;
        }
    }

    bfs(sx, sy);

    cout << (f ? "YES" : "NO");
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