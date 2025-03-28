#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int N = 500, M = 500;
int n, m, x, y;
vector<vector<int>> g(N, vector<int> (M, INT32_MAX));
vector<pair<int, int>> op = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
bool vis[N][M][8];
struct node {
    int i, j, dir, step;
};

void bfs()
{
    queue<node> q;
    for (int dir = 0; dir < 8; dir++)
        q.push({x, y, dir, 0});
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        int i = top.i, j = top.j, dir = top.dir, step = top.step;
        if (vis[i][j][dir] || i < 1 || i > n || j < 1 || j > m)
            continue;
        vis[i][j][dir] = 1;
        g[i][j] = min(g[i][j], step);
        for (int k = 0; k < 8; k++)
            q.push({i + op[dir].first, j + op[dir].second, k, step + 1});
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m >> x >> y;
    bfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (g[i][j] == INT32_MAX)
                cout << -1 << "   ";
            else 
                cout << g[i][j] << "    ";
        cout << "\n";
    }
    return 0;
}