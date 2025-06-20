#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<int> row(n), col(m);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '1')
            {
                row[i]++;
                col[j]++;
                cnt++;
            }
        }
    }

    int r = 0, c = 0;
    for (int i = 0; i < n; i++)
        r += (row[i] == m);
    for (int j = 0; j < m; j++)
        c += (col[j] == n);

    int ok = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '1')
                continue;
            
            if (row[i] == m - 1 && col[j] == n - 1 && row[i] + col[j] == cnt)
                ok++;
        }
    }

    if ((r == 2 && cnt == m * 2) || (c == 2 && cnt == n * 2) || ok == 1 || cnt == 0)
        cout << "YES\n";
    else 
        cout << "NO\n";
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