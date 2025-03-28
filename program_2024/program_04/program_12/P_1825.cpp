#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int N = 310;
int n, m, sx, sy, ans = INT32_MAX;
map<char, vector<int>> transmit;
char g[N][N];
bool vis[N][N];
struct node { 
    int i, j, step;
};

void bfs()
{
    queue<node> q;
    q.push({sx, sy, 0});
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        int i = top.i, j = top.j, step = top.step;
        if (g[i][j] == '=')
        {
            ans = min(ans, step);
            continue;
        }
        if (vis[i][j])
            continue;
        vis[i][j] = 1;
        if (g[i][j] >= 'A' && g[i][j] <= 'Z')
        {
            int x1 = transmit[g[i][j]][0], y1 = transmit[g[i][j]][1],
                x2 = transmit[g[i][j]][2], y2 = transmit[g[i][j]][3];
            if (i == x1 && j == y1)
                i = x2, j = y2;
            else 
                i = x1, j = y1;
        }
        for (auto [x, y] : vector<pair<int, int>> {{-1, 0}, {0, 1}, {1, 0}, {0, -1}})
        {
            int cur_i = i + x, cur_j = j + y;
            if (cur_i < 1 || cur_i > n || cur_j < 1 || cur_j > m || g[cur_i][cur_j] == '#')
                continue;
            q.push({cur_i, cur_j, step + 1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == '@')
                sx = i, sy = j;
            else if (g[i][j] >= 'A' && g[i][j] <= 'Z')
                transmit[g[i][j]].push_back(i), transmit[g[i][j]].push_back(j);
        }
    }
    bfs();
    cout << ans;
    return 0;
}