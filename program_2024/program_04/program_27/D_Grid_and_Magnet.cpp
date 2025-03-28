#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int N = 1005;
char g[N][N];
int bad[N][N];
vector<vector<int>> vis(N, vector<int>(N, -1));
vector<pair<int, int>> op = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    auto valid = [&](int x, int y)
    {
        return x >= 1 && x <= h && y >= 1 && y <= w;
    };
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == '#')
            {
                for (auto [dx, dy] : op)
                {
                    int x = i + dx;
                    int y = j + dy;
                    if (valid(x, y))              
                        bad[x][y] = 1;
                }
            }
        }
    intt ans = 0;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (vis[i][j] == -1 && g[i][j] == '.')
            {
                intt temp = 0;
                queue<pair<int, int>> q;
                vis[i][j] = i * w + j;
                q.push({i, j});
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    temp++;
                    if (bad[x][y])
                        continue;
                    for (auto [u, v] : op)
                    {
                        int nx = x + u;
                        int ny = y + v;
                        if (valid(nx, ny) && vis[nx][ny] != i * w + j)
                        {
                            vis[nx][ny] = i * w + j;
                            q.push({nx, ny});
                        }
                    }
                }
                ans = max(ans, temp);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}