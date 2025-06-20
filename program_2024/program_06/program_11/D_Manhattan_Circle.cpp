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
        vector<vector<char>> g(n + 1, vector<char>(m + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> g[i][j];
        bool f = 0;
        int x = 0, y = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (g[i][j] == '#')
                {
                    for (int k = i; k <= n; k++)
                    {
                        if (g[k][j] != '#')
                        {
                            x = (k - 1 + i) / 2;
                            y = j;
                            f = 1;
                            break;
                        }
                        else if (k == n)
                        {
                            x = (k + i) / 2;
                            y = j;
                            f = 1;
                            break;
                        }
                    }
                }
            }
            if (f)
                break;
        }
        cout << x << " " << y << "\n";
    }
    return 0;
}