#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<vector<int>> pre_odd(n + 2, vector<int>(26)), pre_even(n + 2, vector<int>(26)), suf_odd(n + 2, vector<int>(26)), suf_even(n + 2, vector<int>(26));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            pre_even[i][j] = pre_even[i - 1][j];
            pre_odd[i][j] = pre_odd[i - 1][j];
        }
        if (i % 2 == 1)
            pre_odd[i][s[i] - 'a']++;
        else 
            pre_even[i][s[i] - 'a']++;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            suf_even[i][j] = suf_even[i + 1][j];
            suf_odd[i][j] = suf_odd[i + 1][j];
        }
        if (i % 2 == 1)
            suf_odd[i][s[i] - 'a']++;
        else 
            suf_even[i][s[i] - 'a']++;
    }
    if (n % 2 == 0)
    {
        int mx1 = 0, mx2 = 0;
        for (int j = 0; j < 26; j++)
        {
            mx1 = max(mx1, pre_even[n][j]);
            mx2 = max(mx2, pre_odd[n][j]);
        }
        cout << n - mx1 - mx2 << "\n";
    }
    else 
    {
        int ans = 1e9;
        for (int i = 1; i <= n; i++)
        {
            int mx1 = 0, mx2 = 0;
            for (int j = 0; j < 26; j++)
            {
                mx1 = max(mx1, pre_even[i - 1][j] + suf_odd[i + 1][j]);
                mx2 = max(mx2, pre_odd[i - 1][j] + suf_even[i + 1][j]);
            }
            ans = min(ans, n - mx1 - mx2);
        }
        cout << ans << "\n";
    }
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