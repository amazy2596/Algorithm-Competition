#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int N = 400;
vector<vector<int>> g(N, vector<int>(N, INT32_MAX));
int m, ans = -1;
bool vis[N][N];
struct node {
    int i, j, step;
};

void bfs()
{
    queue<node> q;
    q.push({0, 0, 0});
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        int i = top.i, j = top.j, step = top.step;
        if (vis[i][j])
            continue;
        vis[i][j] = 1;
        if (g[i][j] == INT32_MAX)
        {
            ans = step;
            return;
        }
        for (auto [dx, dy] : vector<pair<int, int>> {{-1, 0}, {0, 1}, {1, 0}, {0, -1}})
        {
            if (i + dx < 0 || i + dx >= 400 || j + dy < 0 || j + dy >= 400)
                continue;
            // cout << "step: " << step << "\n";
            // cout << "t: " << g[i + dx][j + dy] << "\n";
            if (step + 1 < g[i + dx][j + dy])
                q.push({i + dx, j + dy, step + 1});
        }
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        g[x][y] = min(g[x][y], t);
        for (auto [dx, dy] : vector<pair<int, int>> {{-1, 0}, {0, 1}, {1, 0}, {0, -1}})
        {
            if (x + dx < 0 || x + dx > 300 || y + dy < 0 || y + dy > 300)
                continue;
            g[x + dx][y + dy] = min(g[x + dx][y + dy], t);
        }
    }
    // for (int i = 0; i < 5; i++)
        // for (int j = 0; j < 5; j++)
            // if (g[i][j] == INT32_MAX)
                // cout << 0 << " \n"[j == 4];
            // else 
                // cout << g[i][j] << " \n"[j == 4];
    bfs();
    cout << ans;
    return 0;
}