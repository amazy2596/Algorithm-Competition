#include <bits/stdc++.h>
using intt = long long;
using namespace std;

// bool f = 0, ok = 1;
// int cur1, cur2, cur3, cur4;
// int b1, b2, b3, b4;
// vector<int> d1 = {1, 2}, d2 = {2, 1}, d3 = {1, 2}, d4 {2, 1};

// bool check(int a1, int a2, int a3, int a4)
// {
//     if (a1 == b1 && a2 == b2 && a3 == b3 && a4 == b4)
//         return 1;
//     return 0;
// }

// void dfs(int a1, int a2, int a3, int a4)
// {
//     if (check(a1, a2, a3, a4))
//     {
//         f = 1;
//         return;
//     }
//     for (int i = 0; i < 2; i++)
//     {
//         a1 += d1[i], a2 += d2[i], a3 += d3[i], a4 += d4[i];
//         dfs(a1, a2, a3, a4);
//         a1 -= d1[i], a2 -= d2[i], a3 -= d3[i], a4 -= d4[i];
//     }
//     if (a1 = cur1 && a2 == cur2 && a3 == cur3 && a4 == cur4)
//         return;
// }


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
        vector<vector<char>> a(n, vector<char>(m)), b(n, vector<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> b[i][j];
        bool ok = 1;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                if (a[i][j] == b[i][j])
                    continue;
                int dis1 = (b[i][j] - a[i][j] + 3) % 3;
                int dis2 = (dis1 == 1 ? 2 : 1);
                a[i][j] = char(((a[i][j] - '0') + dis1) % 3 + '0');
                a[i + 1][j + 1] = char(((a[i + 1][j + 1] - '0') + dis1) % 3 + '0');
                a[i][j + 1] = char(((a[i][j + 1] - '0') + dis2) % 3 + '0');
                a[i + 1][j] = char(((a[i + 1][j] - '0') + dis2) % 3 + '0'); 
            }
            if (a[i][m - 1] != b[i][m - 1])
            {
                ok = 0;
                break;
            }
        }
        for (int j = 0; j < m ; j++)
            if (a[n - 1][j] != b[n - 1][j])
            {
                ok = 0;
                break;
            }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         f = 0;
        //         for (int k = j + 1; k < m; k++)
        //         {
        //             cur1 = a[i][j] - '0', cur2 = a[i][k] - '0', cur3 = a[i + k - j][j] - '0', cur3 = a[i + k - j][k] - '0';
        //             b1 = b[i][j] - '0', b2 = b[i][k] - '0', b3 = b[i + k - j][j] - '0', b3 = b[i + k - j][k] - '0';
        //             dfs(cur1, cur2, cur3, cur4);
        //         }
        //         if (!f)
        //         {
        //             ok = 0;
        //             break;
        //         }
        //     }
        //     if (!ok)
        //         break;
        // }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}