#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int n, m, ans = 0, g[105][105];
vector<vector<int>> mx(105, vector<int>(105, 0));

int dfs(int i, int j) 
{
    if (mx[i][j])
        return mx[i][j];
    mx[i][j] = 1;
    for (auto [dx, dy] : vector<pair<int, int>> {{0, -1}, {1, 0}, {0, 1}, {-1, 0}})
    {
        int x = i + dx, y = j + dy;
        if (g[x][y] < g[i][j] && x >= 1 && x <= n && y >= 1 && y <= m)
        {
            dfs(x, y);       
            mx[i][j] = max(mx[i][j], mx[x][y] + 1);
        }
    }
    return mx[i][j];
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max(ans, dfs(i, j));
    cout << ans << "\n";
    return 0;
}