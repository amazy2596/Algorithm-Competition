#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, -1));
    string ans;
    for (int i = 0; i < n * n; i++)
    {
        int x1, y1;
        cin >> x1 >> y1;
        if (g[x1][y1] == -1)
        {
            g[x1][y1] = 1;
            ans.push_back('1');
            for (int j = 0; j < a.size(); j++)
            {
                int x2 = a[j].first, y2 = a[j].second;
                int dx = x1 - x2, dy = y1 - y2;
                if (dx == 0)
                    dy = 1;
                else if (dy == 0)
                    dx = 1;
                else 
                {
                    int g = __gcd(abs(dx), abs(dy));
                    dy /= g, dx /= g;
                }
                int nx = x1, ny = y1;
                while (nx >=1 && nx <= n && ny >= 1 && ny <= n)
                {
                    if (g[nx][ny] != 1)
                        g[nx][ny] = 0;
                    nx += dx, ny += dy;
                }
                nx = x1, ny = y1;
                while (nx >=1 && nx <= n && ny >= 1 && ny <= n)
                {
                    if (g[nx][ny] != 1)
                        g[nx][ny] = 0;
                    nx -= dx, ny -= dy;
                }
            }
            a.push_back({x1, y1});
        }
        else 
            ans.push_back('0');
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}