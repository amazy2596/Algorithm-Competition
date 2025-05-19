#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = n - 1; i >= 1; i--)
    {
        if ((s[i][0] == '1' || s[i][1] == '1') && (s[i - 1][0] == '1' || s[i - 1][1] == '1'))
        {
            for (int j = 0; j < 2; j++)
            {
                if (s[i - 1][j] == '1')
                {
                    swap(s[i - 1][j], s[i][j]);
                }
            }
        }
        if ((s[i][2] == '1' || s[i][3] == '1') && (s[i - 1][2] == '1' || s[i - 1][3] == '1'))
        {
            for (int j = 2; j < 4; j++)
            {
                if (s[i - 1][j] == '1')
                {
                    swap(s[i - 1][j], s[i][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << s[i] << "\n";
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