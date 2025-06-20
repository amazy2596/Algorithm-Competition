#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int N = 15;
char g[N][N];
// bool vis_f[N][N][4], vis_c[N][N][4];
int ans = 0, steps = 0;
pair<int, int> op[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
struct node {
    int x, y, dir; 
} F, C;

void print()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
            cout << g[i][j];
        cout << endl;
    }
}

void solve()
{
    while (1)
    {
        // vis_f[F.x][F.y][F.dir] = 1;
        // vis_c[C.x][C.y][C.dir] = 1;
        steps++;
        int i = F.x, j = F.y, dir = F.dir;
        int new_i = i + op[dir].first, new_j = j + op[dir].second;
        if (g[new_i][new_j] == '*' || new_i == 0 || new_i == 11 || new_j == 0 || new_j == 11)
            F.dir = (F.dir + 1) % 4;
        else
        {
            swap(g[i][j], g[new_i][new_j]);
            F.x = new_i, F.y = new_j;
        }
        i = C.x, j = C.y, dir = C.dir;
        new_i = i + op[dir].first, new_j = j + op[dir].second;
        if (g[new_i][new_j] == '*' || new_i == 0 || new_i == 11 || new_j == 0 || new_j == 11)
            C.dir = (C.dir + 1) % 4;
        else 
        {
            swap(g[i][j], g[new_i][new_j]);
            C.x = new_i, C.y = new_j;
        }
        // print();
        if (F.x == C.x && F.y == C.y)
        {
            ans = steps;
            break;  
        }
        if (steps > 1e6)
            break;
    }
    // queue<node> q;
    // q.push(F);
    // while (!q.empty())
    // {
        // node top = q.front();
        // q.pop();
        // int i = top.x, j = top.y, dir = top.dir, steps = top.steps;
        // if (vis[i][j][dir])
            // continue;
        // vis[i][j][dir] = 1;
        // int new_i = op[dir].first + i, new_j = op[dir].second + j;
        // if (g[new_i][new_j] == '*')
            // q.push({i, j, (dir + 1) % 4, steps});
        // else 
            // q.push({new_i, new_j, dir, steps + 1});
    // }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'F')
                F = {i, j, 0};
            else if (g[i][j] == 'C')
                C = {i, j, 0};
        }
    solve();
    cout << ans;
    return 0;
}