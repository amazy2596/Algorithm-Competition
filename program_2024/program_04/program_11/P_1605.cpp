#include <bits/stdc++.h>
using intt = long long;
using namespace std;

// struct node {
    // int i, j;
// };
const int N = 10;
int n, m, t, sx, sy, fx, fy, ans = 0;
vector<vector<int>> g(N, vector<int>(N, 1));
bool vis[N][N];

void dfs(int i, int j)
{
    if (i == fx && j == fy)
    {
        ans++;
        return;
    }
    for (auto [x, y] : vector<pair<int, int>> {{-1, 0}, {1, 0}, {0, -1}, {0, 1}})
    {
        int cur_i = i + x, cur_j = j + y;
        if (cur_i < 1 || cur_i > n || cur_j < 1 || cur_j > m || g[cur_i][cur_j] == 0 || vis[cur_i][cur_j]) 
            continue;
        vis[cur_i][cur_j] = 1;
        dfs(cur_i, cur_j);
        vis[cur_i][cur_j] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = 0;
    }
    vis[sx][sy] = 1;
    dfs(sx, sy);
    cout << ans;
    return 0;
}