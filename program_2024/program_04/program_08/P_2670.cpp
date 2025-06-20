#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int N = 105;
int n, m, ans[N][N];
bool vis[N][N];
char g[N][N];
struct node {
    int x, y;
};


void bfs()
{
    queue<node> q;
    q.push({0, 0}); 
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        int i = top.x, j = top.y;
        if (vis[i][j])
            continue;
        vis[i][j] = 1;
        for (auto [x, y] : vector<node> {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}})
        {
            int new_i = i + x, new_j = j + y;
            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m)
            {
                if (g[i][j] == '*')
                    ans[new_i][new_j]++;
                q.push({new_i, new_j});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    bfs();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (g[i][j] != '*')
                cout << ans[i][j];
            else 
                cout << g[i][j];
        cout << "\n";
    }
    return 0;
}