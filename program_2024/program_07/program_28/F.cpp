#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 5;
int n, m, ans = INT32_MAX;
vector<string> s;
vector<vector<bool>> vis;
struct node
{
    int x, y, steps;
};

void init()
{
    for (int i = 0; i < n; i++)
        vis[i].assign(m, 0);
}

void bfs(int no_dir, int i, int j)
{
    init();
    queue<node> q;
    q.push({i, j, 0});
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        if (top.x == n - 1 && top.y == m - 1 && i == 0 && j == 0)
            ans = min(ans, top.steps);
        if (vis[top.x][top.y])
            continue;
        vis[top.x][top.y] = 1;
        int idx = 0;
        for (auto [dx, dy] : vector<pair<int, int>> {{-1, 0}, {0, 1}, {1, 0}, {0, -1}})
        {
            if (idx == no_dir)  
                continue;
            int x = top.x + dx, y = top.y + dy;
            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if (s[x][y] == 'X')
            {
                vis[x][y] = 1;
                continue;
            }
            q.push({x, y, top.steps + 1});
            idx++;
        }
    }
}

void solve()
{
    cin >> n >> m;
    s.resize(n);
    vis.resize(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++)
        cin >> s[i];
    bfs(4, 0, 0);
    vector<vector<bool>> temp1 = vis;
    bfs(4, n - 1, m - 1);
    vector<vector<bool>> temp2 = vis;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'X' && temp1[i][j] && temp2[i][j])
            {
                s[i][j] = '.';
                bfs(0, 0, 0);
                // bfs(1, 0, 0);
                // bfs(2, 0, 0);
                bfs(3, 0, 0);
                s[i][j] = 'X';
            }
        }
    }
    cout << (ans == INT32_MAX ? -1 : ans) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    solve();
    return 0;
}