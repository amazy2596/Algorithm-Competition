#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> d(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        d[u]++;
        d[v]++;
    }
    string s;
    cin >> s;
    s = ' ' + s;
    int x = 0, y = 0, z = 0, w = 0;
    for (int i = 2; i <= n; i++)
    {
        if (d[i] == 1)
        {
            if (s[i] == '?')
                z++;
            else if (s[i] == '1')
                x++;
            else if (s[i] == '0') 
                y++;
        }
        else if (s[i] == '?')
            w++;
    }
    if (s[1] == '1')
        cout << y + (z + 1) / 2 << "\n";
    else if (s[1] == '0')
        cout << x + (z + 1) / 2 << "\n";
    else if (s[1] == '?')
        cout << max(x, y) + (z + (x == y ? w % 2 : 0)) / 2 << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}