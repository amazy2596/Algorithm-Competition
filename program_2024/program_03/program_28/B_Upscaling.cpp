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
        int n;
        cin >> n;
        vector<vector<char>> g(2 * n, vector<char>(2 * n));
        bool ok = 1, is_jing = 1, is_dian = 0;
        int col = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            for (int j = 0; j < 2 * n; j++)
            {
                if (i % 2 == 1)
                {
                    g[i][j] = g[i - 1][j];
                    continue;
                }
                if (is_jing)
                {
                    g[i][j] = '#';
                    col++;
                    if (col == 2)
                    {
                        is_jing = 0;
                        is_dian = 1;
                        col = 0;
                    }
                }
                else
                {
                    g[i][j] = '.';
                    col++;
                    if (col == 2)
                    {
                        is_dian = 0;
                        is_jing = 1;
                        col = 0;
                    }
                }
                if (j == 2 * n - 1)
                {
                    if (n % 2 == 0)
                    {
                        if (is_jing)
                        {
                            is_jing = 0;
                            is_dian = 1;
                        }
                        else 
                        {
                            is_jing = 1;
                            is_dian = 0;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 2 * n; i++)
        {
            for (int j = 0; j < 2 * n; j++)
                cout << g[i][j];
            cout << "\n";
        }
    }
    return 0;
}