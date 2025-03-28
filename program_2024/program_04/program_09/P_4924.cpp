#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 5, vector<int>(n + 5)), temp(n + 5, vector<int>(n + 5));
    int cnt = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = cnt++;
    while (m--)
    {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        if (z == 0)
        {
            for (int i = -r; i <= r; i++)
                for (int j = -r; j <= r; j++)
                    temp[x + j][y - i] = g[x + i][y + j];
            for (int i = x - r; i <= x + r; i++)
                for (int j = y - r; j <= y + r; j++)
                    g[i][j] = temp[i][j];
        }
        else if (z == 1)
        {
            for (int i = -r; i <= r; i++)
                for (int j = -r; j <= r; j++)
                    temp[x - j][y + i] = g[x + i][y + j];
            for (int i = x - r; i <= x + r; i++)
                for (int j = y - r; j <= y + r; j++)
                    g[i][j] = temp[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cout << g[i][j] << " \n"[j == n];
    return 0;
}