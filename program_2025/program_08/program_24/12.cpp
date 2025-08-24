#include<bits/stdc++.h> 
using namespace std;
using i64 = long long;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> s(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> s[i], s[i] = " " + s[i];

    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            for (int i = 1; i <= m / 2; i++)
            {
                int len = m - 2 * (i - 1);
                for (int j = 0; j < len - 1; j++)
                {
                    char ch = s[i][i + j];
                    s[i][i + j] = s[i + len - 1 - j][i];
                    s[i + len - 1 - j][i] = s[i + len - 1][i + len - 1 - j];
                    s[i + len - 1][i + len - 1 - j] = s[i + j][i + len - 1];
                    s[i + j][i + len - 1] = ch;
                }
            }
        }
        else if (op == 2)
        {
            int x, y;
            cin >> x >> y;
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (s[i][j] == '#')
                        a[i + x - 1][j + y - 1]++;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main( )
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