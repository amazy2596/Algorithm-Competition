#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int N = 105;
int n, m, temp = 0;
vector<vector<int>> ans(N, vector<int>(N, 0));
char g[N][N];
bool vis[N][N];
struct node {
    int i, j;
};

void print()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << ans[i][j];
        cout << endl;
    }
    cout << endl;
}

void bfs(int u, int v)
{
    queue<node> q;
    q.push({u, v});
    while (!q.empty())
    {
        // print();
        node top = q.front();
        q.pop();
        int i = top.i, j = top.j;
        if (vis[i][j])
            continue;
        vis[i][j] = 1;
        bool ok = 1;
        for (auto [x, y] : vector<pair<int, int>> {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}})
        {
            int new_i = i + x, new_j = j + y;
            if (new_i < 1 || new_j < 1 || new_i > n || new_j > m || g[new_i][new_j] != 'W')
                continue;            q.push({new_i, new_j});
            if (ans[new_i][new_j] != 0 && g[i][j] == 'W' && g[new_i][new_j] == 'W')
                ans[i][j] = ans[new_i][new_j];
        }
        if (ok && g[i][j] == 'W' && ans[i][j] == 0)
            ans[i][j] = ++temp;
    }
}

/*
12 20
....WWWW.......WW...
...WW..WW..WWWWW..W.
..WWW.....WW..WW..WW
..WW.....WWWWW.WW.WW
..W...W....W...W.W..
..W...W....WWW.W.W..
........WW.....W.W..
WWWWWW.W..W..WW..WW.
WWWWWW..WW..WW..WWWW
.....W..W..W....W...
WWW.WWW..W..W..W..WW
.WW..W...W..W..W.WWW
*/

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    // for (int i = 1; i <= n; i++)
    // {
        // for (int j = 1; j <= m; j++)
            // cout << g[i][j];
        // cout << endl;
    // }
    // bfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == 'W')
                bfs(i, j);
            // print();
            // if (g[i][j] == 'W')
            // {
                // bool ok = 1;
                // for (auto [x, y] : vector<pair<int, int>> {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}})
                // {
                    // int new_i = i + x, new_j = j + y;
                    // if (new_i < 1 || new_j < 1 || new_i > n || new_j > m)
                        // continue;
                    // if (ans[i][j] == 0 && ans[new_i][new_j] != 0 && g[new_i][new_j] == 'W')
                        // ans[i][j] = ans[new_i][new_j], ok = 0;
                // }
                // if (ok && g[i][j] == 'W')
                    // ans[i][j] = ++temp;
            // }
            
        }
    }
    cout << temp;
    return 0;
}