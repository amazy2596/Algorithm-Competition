#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    int x = -1, y = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '#')
                x = i, y = j;
        }
    }
    
    if (x != n - 1 && y != 0)
    {
        for (int i = 0; i < n - 1; i++)
            cout << "S";
        for (int j = 0; j < m - 1; j++)
            cout << "D";
    }
    else 
    {
        for (int j = 0; j < m - 1; j++)
            cout << "D";
        for (int i = 0; i < n - 1; i++)
            cout << "S";
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}