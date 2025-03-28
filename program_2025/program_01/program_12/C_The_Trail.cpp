#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    string s;
    cin >> n >> m >> s;
    s.push_back(s.back());
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    vector<int> row_sum(n + 1), col_sum(m + 1);
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            sum += g[i][j];
            col_sum[j] += g[i][j];
        }
        row_sum[i] = sum;
    }
        
    int row = 1, col = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'D')
        {
            g[row][col] = -row_sum[row];
            row_sum[row] += g[row][col];
            col_sum[col] += g[row][col];
            row++;
        }
        else if (s[i] == 'R')
        {
            g[row][col] = -col_sum[col];
            row_sum[row] += g[row][col];
            col_sum[col] += g[row][col];
            col++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }

//     cout << "row: ";
//     for (int i = 1; i <= n; i++)
//         cout << row_sum[i] << " ";
//     cout << endl << "col: ";
//     for (int i = 1; i <= m; i++)
//         cout << col_sum[i] << " ";
//     cout << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}