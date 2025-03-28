#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> g[i][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                int mx = 0;
                for (auto [dx, dy] : vector<pair<int, int>> {{0, -1}, {0, 1}, {1, 0}, {-1, 0}})
                {
                    int x = i + dx;
                    int y = j + dy;
                    if (x <= 0 || x > n || y <= 0 || y > m)
                        continue;
                    mx = max(mx, g[x][y]);
                }
                if (g[i][j] > mx)
                    g[i][j] = mx;
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cout << g[i][j] << " \n"[j == m]; 
    }
    return 0;
}