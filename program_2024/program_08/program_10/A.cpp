#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int row = 0, col = 0;
    bool r = 1, c = 1;
    for (int i = 0; i < n; i++)
    {
        bool e = 0;
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'x')
            {
                if (r)
                    row++;
                e = 1;
            }
        }
        if (row)
            r = 0;
        if (e && c)
            col++;
    }
    int t = __gcd(row, col);
    row /= t;
    col /= t;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
            cout << 'x';
        cout << "\n";
    }
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