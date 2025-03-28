#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int N = 1005;
int n, m, k, s, g[N][N];
bool f = 0;
map<pair<int, int>, set<int>> vis;

struct node
{
    int val, x, y;
};

void init()
{
    f = 0;
    vis.clear();
}

void bfs()
{
    queue<node> q;
    q.push({g[1][1], 1, 1});
    vis[{1, 1}].insert(g[1][1]);
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int val = cur.val, i = cur.x, j = cur.y;
        if (i == n && j == m && val == s)
        {
            f = 1;
            return; 
        }
        for (auto [dx, dy] : vector<pair<int, int>> {{1, 0}, {0, 1}})
        {
            int x = i + dx, y = j + dy;
            if (x < 1 || x > n || y < 1 || y > m)
                continue;
            int next_sum = val + g[x][y];
            if (!vis[{x, y}].count(next_sum))
            {
                q.push({next_sum, x, y});
                vis[{x, y}].insert(next_sum);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k >> s;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> g[i][j];
        if (s % k != 0)
            cout << "NO\n";
        else 
        {
            bfs();
            cout << (f ? "YES\n" : "NO\n");
        }
        init();
    }
    return 0;
}