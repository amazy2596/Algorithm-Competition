#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> a(2);
    for (int i = 0; i < 2; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                // cout << a[i ^ 1][j + 1] << " " << a[i ^ 1][j] << " " << a[i][j + 1] << " " << a[i][j];
                if ((a[i ^ 1][j + 1] == 'x' && a[i ^ 1][j] == '.' && a[i][j + 1] == '.' && a[i][j] == '.') ||
                    (a[i][j] == '.' && a[i][j + 1] == 'x' && a[i ^ 1][j] == 'x'))
                    ans++;
            }
            else if (j == n - 1)
            {
                if ((a[i][j] == '.' && a[i][j - 1] == '.' && a[i ^ 1][j] == '.' && a[i ^ 1][j - 1] == 'x') ||
                    (a[i][j] == '.' && a[i][j - 1] == 'x' && a[i ^ 1][j] == 'x'))
                    ans++;
            }
            else
            {
                if ((a[i][j - 1] == '.' && a[i][j] == '.' && a[i][j + 1] == '.' && a[i ^ 1][j] == 'x') ||
                    (a[i][j] == '.' && a[i][j - 1] == 'x' && a[i][j + 1] == 'x' && a[i ^ 1][j] == 'x') ||
                    (a[i][j - 1] == '.' && a[i][j] == '.' && a[i ^ 1][j] == '.' && a[i ^ 1][j - 1] == 'x') ||
                    (a[i][j] == '.' && a[i][j + 1] == '.' && a[i ^ 1][j] == '.' && a[i ^ 1][j + 1] == 'x'))
                    ans++;
            }
        }
    }
    cout << ans << "\n";
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