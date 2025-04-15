#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin>> n;
    vector<vector<char>> s(n + 1, vector<char>(n+ 1, ' '));
    if (n == 1)
        s[n / 2 + 1][n / 2 + 1] = 'L';

    for (int i = 1; i < n; i++) 
        s[1][i] = 'R';
    for (int i = 1; i < n; i++) 
        s[i][n] = 'D';
    for (int i = 2; i <= n; i++) 
        s[n][i] = 'L';
    for (int i = 2; i <= n; i++) 
        s[i][1] = 'U';
    for (int k = 2; k <= (n + 1)/ 2; k++) 
    {
        for (int i = k; i <= n - k; i++) 
            s[k][i] = 'R';
        for (int i = k; i <= n - k; i++) 
            s[i][n - k + 1] = 'D';
        for (int i = k + 1; i <= n - k + 1; i++) 
            s[n - k + 1][i] = 'L';
        for (int i = k + 1; i <= n - k + 1; i++) 
            s[i][k] = 'U';

        s[k][k] = 'L';
        s[n - k + 1][n - k + 1] = 'R';
    }
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j<= n; j++) 
        {
            cout << s[i][j];
        }
        cout << endl;
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