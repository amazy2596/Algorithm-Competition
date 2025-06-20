#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int N = 35;
int n, g[N][N];
bool vis[N][N];

void bfs(int i, int j, int k)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        int x = top.first, y = top.second;
        if (vis[x][y])
            continue;
        vis[x][y] = 1;
        g[x][y] = k;
        for (auto [dx, dy] : vector<pair<int, int>> {{-1, 0}, {0, 1}, {1, 0}, {0, -1}})
        {
            int cur_i = x + dx, cur_j = y + dy;
            if (cur_i < 1 || cur_i > n || cur_j < 1 || cur_j > n || g[cur_i][cur_j] == 1)
                continue;
            q.push({cur_i, cur_j});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    for (int i : {1, n})
    {
        for (int j = 1; j <= n; j++)        
        {
            if (g[i][j] == 0)
                bfs(i, j, 3);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j : {1, n})
        {
            if (g[i][j] == 0)
                bfs(i, j, 3);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j] == 3)
                cout << 0 << " ";
            else if (g[i][j] == 0)
                cout << 2 << " ";
            else 
                cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}