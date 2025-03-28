#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> s(2);
    for (int i = 0; i < 2; i++)
        cin >> s[i];
    int ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (s[1][i - 1] == 'x' && s[1][i] == '.' && s[1][i + 1] == 'x' && s[0][i - 1] == '.' && s[0][i] == '.' && s[0][i + 1] == '.')
            ans++;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (s[0][i - 1] == 'x' && s[0][i] == '.' && s[0][i + 1] == 'x' && s[1][i - 1] == '.' && s[1][i] == '.' && s[1][i + 1] == '.')
            ans++;
    }
    cout << ans << "\n";
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