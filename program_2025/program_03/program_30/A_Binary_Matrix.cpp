#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> rows(n), cols(m);
    map<int, int> row, col;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            rows[i] ^= (ch - '0');
            cols[j] ^= (ch - '0');
        }
    }

    for (int i = 0; i < n; i++)
        if (rows[i] == 1)
            row[i]++;

    for (int i = 0; i < m; i++)
        if (cols[i] == 1)
            col[i]++;

    cout << max(row.size(), col.size()) << "\n";
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