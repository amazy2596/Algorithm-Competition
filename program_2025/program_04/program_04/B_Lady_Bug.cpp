#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n; 
    string s[2];
    cin >> s[0] >> s[1];
    int x = 0, y = 0;
    for (int i = 0, j = 0; j < n; i ^= 1, j++)
    {
        x += (s[i][j] == '1');
        y += (s[i ^ 1][j] == '1');
    }

    if (x + y > n)
    {
        cout << "NO\n";
        return;
    }

    if (x <= n / 2 && y <= ceil(n * 1.0 / 2))
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